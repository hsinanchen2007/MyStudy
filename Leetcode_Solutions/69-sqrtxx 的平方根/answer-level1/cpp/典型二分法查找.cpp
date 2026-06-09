    int mySqrt(int x) {
            double mid = (double)x / 2;
            double right = x;
            double left=0;
            while ((int)left<(int)right)
            {
                if (mid*mid > x)
                {
                    right = mid;
                    mid = (double)(right + left) / 2;
                }
                else
                {
                    left = mid;
                    mid = (double)(right + left) / 2;     
                }		
            }
            return mid;
        }


通过二分法不断逼近left和right的值
当两者的整数部分相等即不满足(int)left<(int)right时便可返回
用float的精度达不到要求，改用double