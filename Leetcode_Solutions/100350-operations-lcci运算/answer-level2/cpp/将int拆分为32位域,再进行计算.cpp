虽然不允许使用位运算& |等，但可使用位域结构，将int拆分为32位，再进行操作。
减法：使用 ‘+’ 相反数；
乘法：使用  多个(a << [b中各位域上的值]) 相‘+’之合， 即2*3 = 2 <<0 + s <<1；
除法：用乘 逼近。

各位域取反：当前位域 = !当前位域;
相反数：各位域取反，再+1；
<<: 伪代码：for(1:n) a+=a;
除法 用乘逼近: 伪代码：for(;n;) s = b*n; 若s >a,则n减少， 若s <a,则n增加。
以下代码只是写完，并未优化（通过,88ms, 14.8MB）：


```
class Operations {
public:
    Operations() {

    }
    
   union INTB
	{
		struct  
		{
			int b0 : 1;
			int b1 : 1;
			int b2 : 1;
			int b3 : 1;
			int b4 : 1;
			int b5 : 1;
			int b6 : 1;
			int b7 : 1;
			int b8 : 1;
			int b9 : 1;
			int b10 : 1;
			int b11 : 1;
			int b12 : 1;
			int b13 : 1;
			int b14 : 1;
			int b15 : 1;
			int b16 : 1;
			int b17 : 1;
			int b18 : 1;
			int b19 : 1;
			int b20 : 1;
			int b21 : 1;
			int b22 : 1;
			int b23 : 1;
			int b24 : 1;
			int b25 : 1;
			int b26 : 1;
			int b27 : 1;
			int b28 : 1;
			int b29 : 1;
			int b30 : 1;
			int b31 : 1;
		};
		int v;
	};

	bool isneg(int a)	// 是否为负
	{
		return ((INTB*)&a)->b31;
	}
	int bitinv(int a)	//	位取反
	{
#define ENOT(av) (av) = !(av)
		INTB* c = ((INTB*)&a);
		ENOT(c->b0);
		ENOT(c->b1);
		ENOT(c->b2);
		ENOT(c->b3);
		ENOT(c->b4);
		ENOT(c->b5);
		ENOT(c->b6);
		ENOT(c->b7);
		ENOT(c->b8);
		ENOT(c->b9);

		ENOT(c->b10);
		ENOT(c->b11);
		ENOT(c->b12);
		ENOT(c->b13);
		ENOT(c->b14);
		ENOT(c->b15);
		ENOT(c->b16);
		ENOT(c->b17);
		ENOT(c->b18);
		ENOT(c->b19);

		ENOT(c->b20);
		ENOT(c->b21);
		ENOT(c->b22);
		ENOT(c->b23);
		ENOT(c->b24);
		ENOT(c->b25);
		ENOT(c->b26);
		ENOT(c->b27);
		ENOT(c->b28);
		ENOT(c->b29);

		ENOT(c->b30);
		ENOT(c->b31);

		return a;
	}
	int inv(int a)		//	相反数
	{
        if (bitinv(a) == 2147483647)//取巧了，vs上不会报错
            return 0x80000000;
		return int(bitinv(a) + 1);
	}
	bool eq(int a, int b) // ==
	{
		return !((long long)(a) + inv(b));
	}
	bool great_u(unsigned int a, unsigned int b)
	{
		INTB* ca = ((INTB*)&a);
		INTB* cb = ((INTB*)&b);
#define CABGU(X, Y) if (X && !Y) return 1; if (Y && !X) return 0;

		CABGU(ca->b31, cb->b31);
		CABGU(ca->b30, cb->b30);

		CABGU(ca->b29, cb->b29);
		CABGU(ca->b28, cb->b28);
		CABGU(ca->b27, cb->b27);
		CABGU(ca->b26, cb->b26);
		CABGU(ca->b25, cb->b25);
		CABGU(ca->b24, cb->b24);
		CABGU(ca->b23, cb->b23);
		CABGU(ca->b22, cb->b22);
		CABGU(ca->b21, cb->b21);
		CABGU(ca->b20, cb->b20);

		CABGU(ca->b19, cb->b19);
		CABGU(ca->b18, cb->b18);
		CABGU(ca->b17, cb->b17);
		CABGU(ca->b16, cb->b16);
		CABGU(ca->b15, cb->b15);
		CABGU(ca->b14, cb->b14);
		CABGU(ca->b13, cb->b13);
		CABGU(ca->b12, cb->b12);
		CABGU(ca->b11, cb->b11);
		CABGU(ca->b10, cb->b10);

		CABGU(ca->b9, cb->b9);
		CABGU(ca->b8, cb->b8);
		CABGU(ca->b7, cb->b7);
		CABGU(ca->b6, cb->b6);
		CABGU(ca->b5, cb->b5);
		CABGU(ca->b4, cb->b4);
		CABGU(ca->b3, cb->b3);
		CABGU(ca->b2, cb->b2);
		CABGU(ca->b1, cb->b1);
		CABGU(ca->b0, cb->b0);

		return 0;
	}
	
	int rol(int a, int rl, bool* outrage =0)		// a << rl
	{
		if (outrage)
			*outrage = 0;
		unsigned long long s = unsigned(a);
		for (int r = rl; r > 0; r += -1)
		{
			s += s;
			unsigned long long sv = s;
			if (outrage)
			{
				int* ls = (int*)&sv;
				*(ls) = 0;
				if (sv)
					*outrage = 1;
				if (s > 0xFFFFFFFF && !*outrage)
				{
					//printf("%d, %d, ");
				}
			}
			
		}
	

		
		return s;
	}
	
	int ror(int a, int rr)		// a >> rl
	{
		INTB* ca = ((INTB*)&a);
		for (; rr > 0; rr += -1)
		{
			ca->b0 = ca->b1;
			ca->b1 = ca->b2;
			ca->b2 = ca->b3;
			ca->b3 = ca->b4;
			ca->b4 = ca->b5;
			ca->b5 = ca->b6;
			ca->b6 = ca->b7;
			ca->b7 = ca->b8;
			ca->b8 = ca->b9;
			ca->b9 = ca->b10;

			ca->b10 = ca->b11;
			ca->b11 = ca->b12;
			ca->b12 = ca->b13;
			ca->b13 = ca->b14;
			ca->b14 = ca->b15;
			ca->b15 = ca->b16;
			ca->b16 = ca->b17;
			ca->b17 = ca->b18;
			ca->b18 = ca->b19;
			ca->b19 = ca->b20;

			ca->b20 = ca->b21;
			ca->b21 = ca->b22;
			ca->b22 = ca->b23;
			ca->b23 = ca->b24;
			ca->b24 = ca->b25;
			ca->b25 = ca->b26;
			ca->b26 = ca->b27;
			ca->b27 = ca->b28;
			ca->b28 = ca->b29;
			ca->b29 = ca->b30;

			ca->b30 = ca->b31;
			ca->b31 = 0;
		}
		return a;
	}

	int minus(int a, int b) {
		return (long long)(a)  + inv(b);
	}

	int multiply(int a, int b, bool* outrage =0) {
		if (eq(a, 0) || eq(b, 0))
			return 0;

// 		a = 0x591d1b60;
// 		b = 3;
	
		bool outraget;
		INTB* cbu = ((INTB*)&b);
		unsigned long long s = 0;
		if (cbu->b0) { s += (unsigned int)rol(a, 0, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b1) { s += (unsigned int)rol(a, 1, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b2) { s += (unsigned int)rol(a, 2, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b3) { s += (unsigned int)rol(a, 3, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b4) { s += (unsigned int)rol(a, 4, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b5) { s += (unsigned int)rol(a, 5, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b6) { s += (unsigned int)rol(a, 6, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b7) { s += (unsigned int)rol(a, 7, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b8) { s += (unsigned int)rol(a, 8, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b9) { s += (unsigned int)rol(a, 9, &outraget); if (outrage && outraget)*outrage = outraget; }

		if (cbu->b10) { s += (unsigned int)rol(a, 10, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b11) { s += (unsigned int)rol(a, 11, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b12) { s += (unsigned int)rol(a, 12, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b13) { s += (unsigned int)rol(a, 13, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b14) { s += (unsigned int)rol(a, 14, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b15) { s += (unsigned int)rol(a, 15, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b16) { s += (unsigned int)rol(a, 16, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b17) { s += (unsigned int)rol(a, 17, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b18) { s += (unsigned int)rol(a, 18, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b19) { s += (unsigned int)rol(a, 19, &outraget); if (outrage && outraget)*outrage = outraget; }

		if (cbu->b20) { s += (unsigned int)rol(a, 20, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b21) { s += (unsigned int)rol(a, 21, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b22) { s += (unsigned int)rol(a, 22, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b23) { s += (unsigned int)rol(a, 23, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b24) { s += (unsigned int)rol(a, 24, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b25) { s += (unsigned int)rol(a, 25, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b26) { s += (unsigned int)rol(a, 26, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b27) { s += (unsigned int)rol(a, 27, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b28) { s += (unsigned int)rol(a, 28, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b29) { s += (unsigned int)rol(a, 29, &outraget); if (outrage && outraget)*outrage = outraget; }

		if (cbu->b30) { s += (unsigned int)rol(a, 30, &outraget); if (outrage && outraget)*outrage = outraget; }
		if (cbu->b31) { s += (unsigned int)rol(a, 31, &outraget); if (outrage && outraget)*outrage = outraget; }
		
		if (outrage)
		{
			unsigned long long sv = s;
			int* ls = (int*)&sv;
			*(ls) = 0;
			if (sv)
				*outrage = 1;
			if (s > 0xFFFFFFFF && !*outrage)
			{
				printf("%d, %d, ");
			}
		}

		return s;
	}
	int divide(int a, int b) {		// a/b
		int aneg = isneg(a);		// 全部转为正数相除
		int bneg = isneg(b);
		if (aneg) a = inv(a);
		if (bneg) b = inv(b);

		if (isneg(minus(a, b)))
			return 0;

		int dsb = 0;
		int dse = 1;
		int dvpre = 0;
		int rtv = 0;
		for (;;)
		{
			bool outragem = 0;
			int dv = multiply(b, dse, &outragem);		// a = ds *b;
			if (eq(dv, a))
			{
				rtv = dse;
				break;
			}
			if (great_u(dv, a) || outragem)	// 过大，则减
			{
				if (eq(dse, (long long)(dsb) + 1))
				{
					rtv = dsb;
					break;
				}
				int ds = ror(minus(dse, dsb), 1);
				dse = minus(dse, ds);
			}
			else// 过小，则加
			{
				int ds = rol(minus(dse, dsb), 1);
				dsb = dse;
				dse = (long long) (dse) + ds;
			}
		}

		if (aneg && bneg || !aneg && !bneg) return rtv;
		return inv(rtv);

	}
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */
```
