    
   #if 1  //解法二，筛选法  1，从2开始，往后，把i 的倍数的元素标记为不是，剩下的就是
    vector<bool> flag(n,true);  //初始化全部为质素
    int cnt = 0;
    for(int i = 2;i < n;i++)
    {
        if(flag[i]) //2是第一个最小的质数，从2开始往后筛选
        {
            //将后面的2的位数全部标记为不是质数
            for(int j = i;j < n;j=j+i)
            {
                flag[j] = false;
            }
            cnt++;
        }
    }
    return cnt;
    #endif