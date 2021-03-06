#include <math.h>

struct Matrix4 {
    float m[4][4];

    Matrix4(){}

    Matrix4(float v){
        m[0][0] = v; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
        m[1][0] = 0; m[1][1] = v; m[1][2] = 0; m[1][3] = 0;
        m[2][0] = 0; m[2][1] = 0; m[2][2] = v; m[2][3] = 0;
        m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = v;
    }

    Matrix4(float v[4][4]){
        m[0][0] = v[0][0]; m[0][1] = v[0][1]; m[0][2] = v[0][2]; m[0][3] = v[0][3];
        m[1][0] = v[1][0]; m[1][1] = v[1][1]; m[1][2] = v[1][2]; m[1][3] = v[1][3];
        m[2][0] = v[2][0]; m[2][1] = v[2][1]; m[2][2] = v[2][2]; m[2][3] = v[2][3];
        m[3][0] = v[3][0]; m[3][1] = v[3][1]; m[3][2] = v[3][2]; m[3][3] = v[3][3];
    }

    void makeIdentity(){
        m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
        m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
        m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
        m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
    }

    void multiply(Matrix4 mat){
        m[0][0] = (m[0][0] * mat.m[0][0]) + (m[1][0] * mat.m[0][1]) + (m[2][0] * mat.m[0][2]) + (m[3][0] * mat.m[0][3]);
        m[0][1] = (m[0][1] * mat.m[0][0]) + (m[1][1] * mat.m[0][1]) + (m[2][1] * mat.m[0][2]) + (m[3][1] * mat.m[0][3]);
        m[0][2] = (m[0][2] * mat.m[0][0]) + (m[1][2] * mat.m[0][1]) + (m[2][2] * mat.m[0][2]) + (m[3][2] * mat.m[0][3]);
        m[0][3] = (m[0][3] * mat.m[0][0]) + (m[1][3] * mat.m[0][1]) + (m[2][3] * mat.m[0][2]) + (m[3][3] * mat.m[0][3]);

        m[1][0] = (m[0][0] * mat.m[1][0]) + (m[1][0] * mat.m[1][1]) + (m[2][0] * mat.m[1][2]) + (m[3][0] * mat.m[1][3]);
        m[1][1] = (m[0][1] * mat.m[1][0]) + (m[1][1] * mat.m[1][1]) + (m[2][1] * mat.m[1][2]) + (m[3][1] * mat.m[1][3]);
        m[1][2] = (m[0][2] * mat.m[1][0]) + (m[1][2] * mat.m[1][1]) + (m[2][2] * mat.m[1][2]) + (m[3][2] * mat.m[1][3]);
        m[1][3] = (m[0][3] * mat.m[1][0]) + (m[1][3] * mat.m[1][1]) + (m[2][3] * mat.m[1][2]) + (m[3][3] * mat.m[1][3]);

        m[2][0] = (m[0][0] * mat.m[2][0]) + (m[1][0] * mat.m[2][1]) + (m[2][0] * mat.m[2][2]) + (m[3][0] * mat.m[2][3]);
        m[2][1] = (m[0][1] * mat.m[2][0]) + (m[1][1] * mat.m[2][1]) + (m[2][1] * mat.m[2][2]) + (m[3][1] * mat.m[2][3]);
        m[2][2] = (m[0][2] * mat.m[2][0]) + (m[1][2] * mat.m[2][1]) + (m[2][2] * mat.m[2][2]) + (m[3][2] * mat.m[2][3]);
        m[2][3] = (m[0][3] * mat.m[2][0]) + (m[1][3] * mat.m[2][1]) + (m[2][3] * mat.m[2][2]) + (m[3][3] * mat.m[2][3]);

        m[3][0] = (m[0][0] * mat.m[3][0]) + (m[1][0] * mat.m[3][1]) + (m[2][0] * mat.m[3][2]) + (m[3][0] * mat.m[3][3]);
        m[3][1] = (m[0][1] * mat.m[3][0]) + (m[1][1] * mat.m[3][1]) + (m[2][1] * mat.m[3][2]) + (m[3][1] * mat.m[3][3]);
        m[3][2] = (m[0][2] * mat.m[3][0]) + (m[1][2] * mat.m[3][1]) + (m[2][2] * mat.m[3][2]) + (m[3][2] * mat.m[3][3]);
        m[3][3] = (m[0][3] * mat.m[3][0]) + (m[1][3] * mat.m[3][1]) + (m[2][3] * mat.m[3][2]) + (m[3][3] * mat.m[3][3]);
    }

    static Matrix4 multiply(Matrix4 m1, Matrix4 m2){
        Matrix4 mat;

        mat.m[0][0] = (m1.m[0][0] * m2.m[0][0]) + (m1.m[1][0] * m2.m[0][1]) + (m1.m[2][0] * m2.m[0][2]) + (m1.m[3][0] * m2.m[0][3]);
        mat.m[0][1] = (m1.m[0][1] * m2.m[0][0]) + (m1.m[1][1] * m2.m[0][1]) + (m1.m[2][1] * m2.m[0][2]) + (m1.m[3][1] * m2.m[0][3]);
        mat.m[0][2] = (m1.m[0][2] * m2.m[0][0]) + (m1.m[1][2] * m2.m[0][1]) + (m1.m[2][2] * m2.m[0][2]) + (m1.m[3][2] * m2.m[0][3]);
        mat.m[0][3] = (m1.m[0][3] * m2.m[0][0]) + (m1.m[1][3] * m2.m[0][1]) + (m1.m[2][3] * m2.m[0][2]) + (m1.m[3][3] * m2.m[0][3]);

        mat.m[1][0] = (m1.m[0][0] * m2.m[1][0]) + (m1.m[1][0] * m2.m[1][1]) + (m1.m[2][0] * m2.m[1][2]) + (m1.m[3][0] * m2.m[1][3]);
        mat.m[1][1] = (m1.m[0][1] * m2.m[1][0]) + (m1.m[1][1] * m2.m[1][1]) + (m1.m[2][1] * m2.m[1][2]) + (m1.m[3][1] * m2.m[1][3]);
        mat.m[1][2] = (m1.m[0][2] * m2.m[1][0]) + (m1.m[1][2] * m2.m[1][1]) + (m1.m[2][2] * m2.m[1][2]) + (m1.m[3][2] * m2.m[1][3]);
        mat.m[1][3] = (m1.m[0][3] * m2.m[1][0]) + (m1.m[1][3] * m2.m[1][1]) + (m1.m[2][3] * m2.m[1][2]) + (m1.m[3][3] * m2.m[1][3]);

        mat.m[2][0] = (m1.m[0][0] * m2.m[2][0]) + (m1.m[1][0] * m2.m[2][1]) + (m1.m[2][0] * m2.m[2][2]) + (m1.m[3][0] * m2.m[2][3]);
        mat.m[2][1] = (m1.m[0][1] * m2.m[2][0]) + (m1.m[1][1] * m2.m[2][1]) + (m1.m[2][1] * m2.m[2][2]) + (m1.m[3][1] * m2.m[2][3]);
        mat.m[2][2] = (m1.m[0][2] * m2.m[2][0]) + (m1.m[1][2] * m2.m[2][1]) + (m1.m[2][2] * m2.m[2][2]) + (m1.m[3][2] * m2.m[2][3]);
        mat.m[2][3] = (m1.m[0][3] * m2.m[2][0]) + (m1.m[1][3] * m2.m[2][1]) + (m1.m[2][3] * m2.m[2][2]) + (m1.m[3][3] * m2.m[2][3]);

        mat.m[3][0] = (m1.m[0][0] * m2.m[3][0]) + (m1.m[1][0] * m2.m[3][1]) + (m1.m[2][0] * m2.m[3][2]) + (m1.m[3][0] * m2.m[3][3]);
        mat.m[3][1] = (m1.m[0][1] * m2.m[3][0]) + (m1.m[1][1] * m2.m[3][1]) + (m1.m[2][1] * m2.m[3][2]) + (m1.m[3][1] * m2.m[3][3]);
        mat.m[3][2] = (m1.m[0][2] * m2.m[3][0]) + (m1.m[1][2] * m2.m[3][1]) + (m1.m[2][2] * m2.m[3][2]) + (m1.m[3][2] * m2.m[3][3]);
        mat.m[3][3] = (m1.m[0][3] * m2.m[3][0]) + (m1.m[1][3] * m2.m[3][1]) + (m1.m[2][3] * m2.m[3][2]) + (m1.m[3][3] * m2.m[3][3]);

        return mat;
    }

    void setOrthoganalProjectionMatrix(float left, float right, float bottom, float top){
        m[0][0] = 2 / (right - left);
        m[1][1] = 2 / (top - bottom);
        m[3][0] = -((right + left) / (right - left));
        m[3][1] = -((top + bottom) / (top - bottom));
    }

    void scale2D(float x, float y){
        m[0][0] = x;
        m[1][1] = y;
    }

    void translate2D(float x, float y){
        m[3][0] += x;
        m[3][1] += y;
    }

    void rotateX(float amt){
        Matrix4 rot(1);
        rot.m[1][1] = cos(amt);
        rot.m[2][2] = cos(amt);
        rot.m[2][1] = -sin(amt);
        rot.m[1][2] =  sin(amt);
        *this = multiply(rot, *this);
    }
    
    void rotateY(float amt){
        Matrix4 rot(1);
        rot.m[0][0] = cos(amt);
        rot.m[2][2] = cos(amt);
        rot.m[2][0] = sin(amt);
        rot.m[0][2] = -sin(amt);
        *this = multiply(rot, *this);
    }
    
    void rotateZ(float amt){
        Matrix4 rot(1);
        rot.m[0][0] = cos(amt);
        rot.m[1][1] = cos(amt);
        rot.m[1][0] = -sin(amt);
        rot.m[0][1] =  sin(amt);
        *this = multiply(rot, *this);
    }
};