# 快排模板记录 
``
x取左值 则  递归时  去下表j



  **l一般为 0  r 为n-1 **

`void quick_sort(vector<int>& q,int l,int r){
    
    if(l>=r) retun;
    
    int i=l-1;
    int j=r+1;  //方便计算
    int  x=q[l]; //  参考值
    
    
    while (i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
        
    }
    quick_sort(q,l,j);
    
    
    quick_sort(q,j+1,r);
    
}