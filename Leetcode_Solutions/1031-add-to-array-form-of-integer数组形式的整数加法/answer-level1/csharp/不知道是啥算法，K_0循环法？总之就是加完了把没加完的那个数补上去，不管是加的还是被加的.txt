List<int> lst = new List<int>();
            int i = A.Length - 1;
            while (K > 0)
            {
                if (A[i] + K % 10 >= 10)
                {
                    lst.Insert(0,A[i] + K % 10 - 10);
                    K = K / 10 + 1;
                    i--;
                }
                else
                {
                    lst.Insert(0,A[i] + K%10);
                    K = K/10;
                    i--;
                }
                if (i == -1)
                {
                    while(K>0)
                    {
                        lst.Insert(0, K % 10);
                        K = K / 10;
                    }
                }
            }
            if(i>=0)
            {
                for(int j=i;j>=0;j--)
                {
                    lst.Insert(0, A[j]);
                }
            }
            return lst;



加上415那道题的好点的解法，再写一遍也通过了
![无标题.png](https://pic.leetcode-cn.com/42bfd392609c43ca4a99b0dd1d6598e9655b6f26c6cae4137ea48579d09fe645-%E6%97%A0%E6%A0%87%E9%A2%98.png)
