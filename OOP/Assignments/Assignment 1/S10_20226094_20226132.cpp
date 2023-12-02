#include <iostream>

using namespace std;

class Point
{
private:
    int x,y;
public:
    void setXY(int nx,int ny)
    {
        x = nx;
        y = ny;
    }
    int getX()
    {
        return x;
    }      
    int getY()
    {
        return y;
    }
    void print()
    {
        cout << "(" << x << "," << y << ")";
    }

    friend ostream& operator<<(ostream& os, const Point& p);
    friend istream& operator>>(istream& is, Point& p)
    {
        is >> p.x >> p.y;
        return is;
    }
};


class PointsArray
{
private:
    Point** array;
    int rows;
    int columns;
public:

    friend ostream& operator<<(ostream& os, const PointsArray& pa);
    friend istream& operator>>(istream& is, PointsArray& pa);
    PointsArray& operator=(const PointsArray& pa);
    PointsArray& operator+(int n);

    // Constructor
    PointsArray(int nr, int nc)
    {
        rows = nr ; columns = nc;
        array = new Point*[rows];
        for(int i = 0; i < rows; i++)
        {
            array[i] = new Point[columns];
        }
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < columns; j++)
            {
                array[i][j].setXY(0,0);
            }
    }
    // Copy Constructor
    PointsArray(const PointsArray &obj)
    {
        rows = obj.rows;
        columns = obj.columns;
        array = new Point*[rows];
        for(int i = 0; i < rows; i++)
        {
            array[i] = new Point[columns];
            for(int j = 0; j < columns; j++)
            {
                array[i][j] = obj.array[i][j];
            }
        }
    }
    int getRows() const
    {
        return rows;
    }
    int getColumns() const
    {
        return columns;
    }

    void setPoint(int row, int col, const Point &p);
    void swapRows(int r1, int r2);
    void deleteColumn(int c);
    void addColumn(int col, Point* column);
    void print() const;


    // Destructor
    ~PointsArray() {
        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }
};

ostream &operator<<(ostream &os, const PointsArray &pa)
{
    for(int i = 0; i < pa.getRows(); i++)
        for(int j = 0; j < pa.getColumns(); j++)
        {
            pa.array[i][j].print();
            os << "";
        }
    return os;
}

istream &operator>>(istream &is, PointsArray &pa)
{
    for(int i = 0; i < pa.getRows(); i++)
        for(int j = 0; j < pa.getColumns(); j++)
        {
            is >> pa.array[i][j];
        }
    return is;
}   

PointsArray &PointsArray::operator=(const PointsArray &pa)
{
    if (this != &pa) {
        Point** newArray = new Point*[pa.rows];
        for (int i = 0; i < pa.rows; ++i) {
            newArray[i] = new Point[pa.columns];
            for (int j = 0; j < pa.columns; ++j) {
                newArray[i][j] = pa.array[i][j];
            }   
        }

        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;

        rows = pa.rows;
        columns = pa.columns;
        array = newArray;
    }
    return *this;
}

PointsArray &PointsArray::operator+(int value) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int nX = array[i][j].getX() + value;
            int nY = array[i][j].getY() + value;
            array[i][j].setXY(nX, nY);
        }
    }

    return *this;
}

void PointsArray::setPoint(int row, int col, const Point &p)
{
    if(row >= 0 && row <= rows && col >= 0 && col <= columns)
    {
        array[row][col] = p;
    }
    else
    {
        cout << "Invalid row and column" << endl;
    }
}

void PointsArray::swapRows(int r1, int r2) {
    if (r1 >= 0 && r1 < rows && r2 >= 0 && r2 < rows) {
        Point* temp = array[r1];
        array[r1] = array[r2];
        array[r2] = temp;
    } else {
        cout << "Invalid indices" << endl;
    }
}

void PointsArray::addColumn(int col, Point* column) 
{
    if (col >= 0 && col <= columns) {
        Point** newArray = new Point*[rows];
        for (int i = 0; i < rows; ++i) {
            newArray[i] = new Point[columns + 1];

            for (int j = 0; j < col; ++j) {
                newArray[i][j] = array[i][j];
            }

            newArray[i][col] = column[i];

            for (int j = col + 1; j < columns + 1; ++j) {
                newArray[i][j] = array[i][j - 1];
            }
        }

        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;

        array = newArray;
        columns++;
    } else {
        cout << "Invalid column index" << endl;
    }
}

void PointsArray::deleteColumn(int c) 
{
    if (c >= 0 && c < columns) {
        for (int i = 0; i < rows; ++i) {
            for (int j = c; j < columns - 1; ++j) {
                array[i][j] = array[i][j + 1];
            }
        }
        columns--;
    } else {
        cout << "Invalid column index" << endl;
    }
}

void PointsArray::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j].print();
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    PointsArray pa(0, 0);

    do {
        std::cout << "\nMenu:\n"
                  << "1. Initialize PointsArray\n"
                  << "2. Copy PointsArray\n"
                  << "3. Display Number of Rows\n"
                  << "4. Display Number of Columns\n"
                  << "5. Enter PointsArray Elements\n"
                  << "6. Display PointsArray Elements\n"
                  << "7. Add Integer to PointsArray\n"
                  << "8. Swap Rows\n"
                  << "9. Delete Column\n"
                  << "10. Add Column\n"
                  << "11. Print PointsArray as Matrix\n"
                  << "12. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int rows, columns;
                std::cout << "Enter the number of rows: ";
                std::cin >> rows;
                std::cout << "Enter the number of columns: ";
                std::cin >> columns;
                pa = PointsArray(rows, columns);
                break;
            }
            case 2: {
                PointsArray copyOfPA(pa);
                std::cout << "Copied PointsArray:\n";
                std::cout << copyOfPA;
                break;
            }
            case 3:
                std::cout << "Number of Rows: " << pa.getRows() << std::endl;
                break;
            case 4:
                std::cout << "Number of Columns: " << pa.getColumns() << std::endl;
                break;
            case 5:
                std::cout << "Enter PointsArray Elements:\n";
                std::cin >> pa;
                break;
            case 6:
                std::cout << "PointsArray Elements:\n" << pa;
                break;
            case 7: {
                int value;
                std::cout << "Enter an integer to add to PointsArray: ";
                std::cin >> value;
                pa = pa + value;
                break;
            }
            case 8: {
                int row1, row2;
                std::cout << "Enter the row indices to swap: ";
                std::cin >> row1 >> row2;
                pa.swapRows(row1, row2);
                break;
            }
            case 9: {
                int col;
                std::cout << "Enter the column index to delete: ";
                std::cin >> col;
                pa.deleteColumn(col);
                break;
            }
            case 10: {
                int col;
                std::cout << "Enter the column index to add: ";
                std::cin >> col;

                Point* newColumn = new Point[pa.getRows()];
                std::cout << "Enter the points for the new column:\n";
                for (int i = 0; i < pa.getRows(); ++i) {
                    std::cin >> newColumn[i];
                }

                pa.addColumn(col, newColumn);
                delete[] newColumn;
                break;
            }
            case 11:
                std::cout << "PointsArray as Matrix:\n";
                pa.print();
                break;
            case 12:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 12);

    return 0;
}   
