### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        // boolean flag[]=new boolean[n];
        // int result=0;
        // int a=0;//指针不断增加，0指向0,1指向1,5个为一个循环，10指向的是0；
        // int b=0;//寻找第m个数，若flag=false
        // int sum=0;

        // while(true){
        //     int point1=a%n;
        //     int point2=b%m;
        //     if(point2==m-1){
        //             flag[point1]=true;
        //             sum=sum+1;
        //             b=-1;
        //     }
        //     if(sum==n-1){
        //         break;
        //     }
        //     a++;
        //     while(flag[a%n]==true){
        //         a++;
        //     }
        //     b++;

        // }
        // for(int i=0;i<n;i++){
        //     if(flag[i]==false){
        //         result=i;
        //         break;
        //     }
        // }
        // return result;
        // return n == 1 ? 0 : (lastRemaining(n - 1, m) + m) % n;
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            list.add(i);
        }
        int start=0;
        while(list.size() > 1) {
            int size = list.size();
            int next = (m + start - 1) % size;
            list.remove(next);
            start = next;
        }
        return list.get(0);
}}
```