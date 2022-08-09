#include <iostream>
#include <cmath>
#include "complex.h"
using namespace std;
int main()
{
	int n = 1;
	while (n) {
		cout << "������ֵ������" << endl << "�����뺯��(���κ���a=0)ax^3+bx^2+cx+d" << endl << "a=";
		double a, b, c, d, min, max;

		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "c=";
		cin >> c;
		cout << "d=";
		cin >> d;
		cout << "�����뷶Χ��min��max������Ҫʹ���������������һ���ϴ���С������" << endl << "min=";
		cin >> min;
		cout << "max=";
		cin >> max;
		while (min > max)
		{
			cout << "min>max ����������" << endl;
			cout << "min=";
			cin >> min;
			cout << "max=";
			cin >> max;
		}
		if (a != 0) {
			double p = (3 * a * c - b * b) / (3 * a * a);
			double q = (27 * a * a * d - 9 * a * b * c + 2 * b * b * b) / (27 * a * a * a);
			complex w = complex(-1.0 / 2.0, sqrt(3) / 2);
			complex ww = w.power(2);
			double M = sqrt(pow(q / 2, 2) + pow(p / 3, 3));
			complex r = pow((-q / 2) + M, 1.0 / 3.0); complex s = pow((-q / 2) - M, 1.0 / 3.0);
			complex x1 = r + s;
			complex x2 = w * r + ww * s;
			complex x3 = ww * r + w * s;
			cout << "x1=" << x1 << endl;
			cout << "x2=" << x2 << endl;
			cout << "x3=" << x3 << endl;
		}
		
		if (a > 0) {
			//3ax^2+2bx^2+c
			double e = 4 * b * b - 12 * a * c;
			if (e > 0)
			{
				double f = sqrt(e);
				double x1 = (-2 * b - f) / (6 * a);
				double x2 = (-2 * b + f) / (6 * a);
				cout.precision(2);
				cout.setf(ios::fixed);
				if (min <= x1 && x1 < x2 && x2 <= max) {
					double fx1, fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
					fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
					fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x1 + d;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					if (fx1 > fmax) { fxmax = fx1; xmax = x1; }
					else { fxmax = fmax; xmax = max; }
					if (fx2 < fmin) { fxmin = fx2; xmin = x2; }
					else { fxmin = fmin; xmin = min; }
					cout << "���ֵ=" << "f(" << xmax << ")=" << fxmax << "��"
						<< "��Сֵ=" << "f(" << xmin << ")=" << fxmin << endl
						<< "����ֵ" << "f(" << x1 << ")=" << fx1 << ",  "
						<< "��Сֵ" << "f(" << x2 << ")=" << fx2;
				}
				if (min <= x1 && x1 <= max && max < x2) {
					double fx1, fmin, fmax, fxmin, fxmax, xmax, xmin;
					fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					fxmax = fx1; xmax = x1;
					if (fmax < fmin) { fxmin = fmax; xmin = max; }
					else { fxmin = fmin; xmin = min; }
					cout << "���ֵ=" << "f(" << x1 << ")=" << fx1 << "��"
						<< "��Сֵ=" << "f(" << xmin << ")=" << fxmin << endl
						<< "����ֵ=" << "f(" << x1 << ")=" << fx1 << ",  "
						<< "�޼�Сֵ";
				}
				if (x1 < min && min <= x2 && x2 <= max) {
					double fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
					fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x1 + d;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					fxmin = fx2; xmin = x2;
					if (fmin > fmax) { fxmax = fmin; xmax = min; }
					else { fxmax = fmax; xmax = max; }
					cout << "���ֵ=" << "f(" << xmax << ")=" << fxmax << "��"
						<< "��Сֵ=" << "f(" << x2 << ")=" << fx2 << endl
						<< "��Сֵ=" << "f(" << x2 << ")=" << fx2 << ",  "
						<< "�޼���ֵ";
				}
				if (x1 < min && min <= max && max < x2) {
					double fmin, fmax;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					cout << "���ֵ=" << "f(" << min << ")=" << fmin << "��"
						<< "��Сֵ=" << "f(" << max << ")=" << fmax << endl
						<< "�޼���ֵ" << ",  "
						<< "�޼�Сֵ";
				}
				if (x2<min || x1>max)
				{
					double fxmin, fxmax;
					fxmin = a * min * min * min + b * min * min + c * min + d;
					fxmax = a * max * max * max + b * max * max + c * max + d;
					cout << "���ֵ=" << "f(" << max << ")=" << fxmax << "��"
						<< "��Сֵ=" << "f(" << min << ")=" << fxmin << endl
						<< "�޼���ֵ" << ",  "
						<< "�޼�Сֵ";
				}
			}
			if (e <= 0) {
				double fxmin, fxmax;
				fxmin = a * min * min * min + b * min * min + c * min + d;
				fxmax = a * max * max * max + b * max * max + c * max + d;
				cout << "���ֵ=" << "f(" << max << ")=" << fxmax << "��"
					<< "��Сֵ=" << "f(" << min << ")=" << fxmin << endl
					<< "�޼���ֵ" << ",  "
					<< "�޼�Сֵ";
			}
		}



		if (a < 0) {
			//3ax^2+2bx+c
			double e = 4 * b * b - 12 * a * c;
			if (e > 0)
			{
				double f = sqrt(e);
				double x2 = (-2 * b - f) / (6 * a);
				double x1 = (-2 * b + f) / (6 * a);
				cout.precision(2);
				cout.setf(ios::fixed);
				if (min <= x1 && x2 <= max) {
					double fx1, fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
					fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
					fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x1 + d;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					if (fx2 > fmin) { fxmax = fx2; xmax = x2; }
					else { fxmax = fmin; xmax = min; }
					if (fx1 < fmax) { fxmin = fx1; xmin = x1; }
					else { fxmin = fmax; xmin = max; }
					cout << "���ֵ=" << "f(" << xmax << ")=" << fxmax << "��"
						<< "��Сֵ=" << "f(" << xmin << ")=" << fxmin << endl
						<< "����ֵ" << "f(" << x2 << ")=" << fx2 << ",  "
						<< "��Сֵ" << "f(" << x1 << ")=" << fx1;
				}
				if (min <= x1 && x1 <= max && max < x2) {
					double fx1, fmin, fmax, fxmin, fxmax, xmax, xmin;
					fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					fxmin = fx1; xmin = x1;
					if (fmin > fmax) { fxmax = fmin; xmax = min; }
					else { fxmax = fmax; xmax = max; }
					cout << "���ֵ=" << "f(" << xmax << ")=" << fxmax << "��"
						<< "��Сֵ=" << "f(" << x1 << ")=" << fx1 << endl
						<< "��Сֵ=" << "f(" << x1 << ")=" << fx1 << ",  "
						<< "�޼���ֵ";
				}
				if (x1 < min && min <= x2 && x2 <= max) {
					double fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
					fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x2 + d;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					fxmax = fx2; xmax = x2;
					if (fmax < fmin) { fxmin = fmax; xmin = max; }
					else { fxmin = fmin; xmin = min; }
					cout << "���ֵ=" << "f(" << x2 << ")=" << fx2 << "��"
						<< "��Сֵ=" << "f(" << xmin << ")=" << fxmin << endl
						<< "����ֵ=" << "f(" << x2 << ")=" << fx2 << ",  "
						<< "�޼�Сֵ";
				}
				if (x1 < min && min <= max && max < x2) {
					double fxmin, fxmax;
					fxmin = a * min * min * min + b * min * min + c * min + d;
					fxmax = a * max * max * max + b * max * max + c * max + d;
					cout << "���ֵ=" << "f(" << max << ")=" << fxmax << "��"
						<< "��Сֵ=" << "f(" << min << ")=" << fxmin << endl
						<< "�޼���ֵ" << ",  "
						<< "�޼�Сֵ";
				}
				if (x2<min || x1>max) {
					double fmin, fmax;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					cout << "���ֵ=" << "f(" << min << ")=" << fmin << "��"
						<< "��Сֵ=" << "f(" << max << ")=" << fmax << endl
						<< "�޼���ֵ" << ",  "
						<< "�޼�Сֵ";
				}
			}
			if (e <= 0) {
				double fmin, fmax;
				fmin = a * min * min * min + b * min * min + c * min + d;
				fmax = a * max * max * max + b * max * max + c * max + d;
				cout << "���ֵ=" << "f(" << min << ")=" << fmin << "��"
					<< "��Сֵ=" << "f(" << max << ")=" << fmax << endl
					<< "�޼���ֵ" << ",  "
					<< "�޼�Сֵ";
			}

		}

		if (a == 0) { //2bx+c 
			double x0 = -c / 2 * b;
			double fmin = b * min * min + c * min + d;
			double fmax = b * max * max + c * max + d;
			double fxmax, fxmin, xmax, xmin;
			double fx0 = b * x0 * x0 + c * x0 + d;
			if (min <= x0 && x0 <= max)
			{
				if (b > 0) {
					fxmin = fx0; xmin = x0;
					if (fmin > fmax) { fxmax = fmin; xmax = min; }
					else { fxmax = fmax; xmax = max; }
					cout << "��Сֵ=" << "f(" << xmin << ")=" << fxmin << "��"
						<< "���ֵ=" << "f(" << xmax << ")=" << fxmax << endl;
				}
				if (b < 0) {
					fxmax = fx0; xmax = x0;
					if (fmax < fmin) { fxmin = fmax; xmin = max; }
					else { fxmin = fmin; xmin = min; }
					cout << "��Сֵ=" << "f(" <<xmin << ")=" << fxmin << "��"
						<< "���ֵ=" << "f(" << xmax << ")=" << fxmax << endl;
				}
				if (b == 0) {
					if (fmin > fmax) { fxmax = fmin; xmax = min; }
					else { fxmax = fmax; xmax = max; }
					if (fmax < fmin) { fxmin = fmax; xmin = max; }
					else { fxmin = fmin; xmin = min; }
					cout << "��Сֵ=" << "f(" << xmin << ")=" << fxmin << "��"
						<< "���ֵ=" << "f(" << xmax << ")=" << fxmax << endl;
				}

			}
			if (x0<min || x0>max) {
				if (fmin > fmax) { fxmax = fmin; xmax = min; }
				else { fxmax = fmax; xmax = max; }
				if (fmax < fmin) { fxmin = fmax; xmin = max; }
				else { fxmin = fmin; xmin = min; }
				cout << "��Сֵ=" << "f(" << xmin << ")=" << fxmin << "��"
					<< "���ֵ=" << "f(" <<xmax << ")=" << fxmax << endl;

			}
		}




		cout << endl << "�������뺯������1���˳�����0" << endl;
		cin >> n;
	}
	return 0;
}


