int minIncrementForUnique(int* A, int ASize){
    int l[100000]={0};  //记录每个数的出现次数，l的范围最好大一点，否则可能会因为max_越界
    int max_=0;int min_=100000;
    for (int i=0;i<ASize;i++){
        l[A[i]]++;
        if(max_<A[i]){
            max_=A[i];
        }
        if(min_>A[i]){
            min_=A[i];
        }
    }
    int sum=0;
    for (int i=min_;i<=max_;i++){
        if(l[i]<=1)continue;
        else{  
            l[i+1]+=l[i]-1;         //只让了l[i]的值为1或0，重复的数交给l[i+1];
            sum+=l[i]-1;
            l[i]=1;
        }
    }
    while(l[max_+1]>=1){   //判断l[max_+1]不是0的情况
        max_++;
        sum+=l[max_]-1;
        l[max_+1]=l[max_]-1;
        l[max_]=1;
    }
    return sum;
}
![c3ff15dd692a1c5e9f2f4749d612a00.png](https://pic.leetcode-cn.com/acba691ff63656a1aa58751208b6c3f550d7c34a2b846e015269f38fc504213f-c3ff15dd692a1c5e9f2f4749d612a00.png)

