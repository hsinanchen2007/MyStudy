1.方法一：双指针版
2.从左往右遍历,找出不符合奇数和偶数的下标进行交换;
3.方法二：空间复杂度O(n)
4.遍历A数组,一次判断每个数字是奇是偶,存放到B数组;
5.完结。

        //方法一：
        public int[] sortArrayByParityII(int[] A) {
            int even = 0, odd = 1;

            while (even < A.length && odd < A.length) {
                while (even < A.length && A[even] % 2 == 0)
                    even += 2;
                while (odd < A.length && A[odd] % 2 != 0)
                    odd += 2;
                if (even < A.length && odd < A.length) {
                    int temp = A[even];
                    A[even] = A[odd];
                    A[odd] = temp;
                }
                even += 2;
                odd += 2;
            }
            return A;
        }


        //方法二：
        public int[] sortArrayByParityII(int[] A) {
            int[] B = new int[A.length];
            int even = 0, odd = 1;

            for (int i : A) {
                if (i % 2 == 0) {
                    B[even] = i;
                    even += 2;
                } else {
                    B[odd] = i;
                    odd += 2;
                }
            }

            return B;
        }