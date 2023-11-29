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
    PointsArray& operator+(int n) const;

    // Constructor
    PointsArray(int nr, int nc)
    {
        nr = rows; columns = nc;
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


int main()
{
    
    return 0;
}