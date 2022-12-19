用if 映射数值
把对应值装入数组
判断相邻的两个值是否前小后大，减前小
前大后小 ，加前大
指针后移后判断是否是最后一个值，做加法即可。


// int turnNum(char c) ;
int romanToInt(char * s){
    //考虑一个字符情况
    int i=0;
    for( i=0;s[i]!='\0';i++); //共0 ->i-1   i个字符
    if(i==1)
    {
        char c;
        c=s[0];
          if(c=='I') return 1;
          if(c=='V') return 5;
          if(c=='X') return 10;
          if(c=='L') return 50;
          if(c=='C') return 100;
          if(c=='D') return 500;
          if(c=='M') return 1000;

    }
         
    int nums[i];
    for(int j=0;j<i;j++)
    {
          char c;
          int num=0;
          c=s[j];
          if(c=='I') num= 1;
          if(c=='V') num=  5;
          if(c=='X') num=  10;
          if(c=='L') num=  50;
          if(c=='C') num=  100;
          if(c=='D') num=  500;
          if(c=='M') num=  1000;
          nums[j]=num;
        
           //将对于罗马数字转换成整数放入数组
    }

    // 1 5    1 10 
    // 10 50  10 100
    // 100 500   100  1000

    // 两个指针指向相邻俩数，如果数一小于数2 说明是作减，其余正常相加即可。

    int sum =0; //存放转化后的结果
    //特例都是小的在前 大的在后
    for(int p=0,q=1;q<i;  )
    {
        if(nums[p]<nums[q])   //特例出现 ,作减前一个值
        {
            sum-=nums[p];
            p+=1;
            q+=1;
            if(p==(i-1))  
            {
                sum+=nums[p];
            } 
        }
        else
        {
            sum+=nums[p];   // 正常情况，只加前一个值，指针后移一位。
            p++;
            q++;
            if(p==(i-1))  
            {
                sum+=nums[p];
            }           //考虑末尾情况，q已经超标，但p为最后一个元素，还没有加入，做一个判断。
        }
    }

    return sum;
    
}

/*int turnNum(char c)  
{
    if(c=='I') return 1;
    if(c=='V') return 5;
    if(c=='X') return 10;
    if(c=='L') return 50;
    if(c=='C') return 100;
    if(c=='D') return 500;
    if(c=='M') return 1000;
}
*/
    
