题目很简单，从数组中开始考虑，若数组中间某段为....1,0,0,0,1...，若在此段中间坐可达到的最大的话，则很容易看出来坐在第一个1和第二个1的中间，那么第一个1的位置为j第二个位置的为i的话，则最大距离为（i-j）/2;
可以考虑设置一个参数j保存最后一个出现1得到位置
```
int j；
for(.........){
  if(seat==1){
      j=最后一个1出现的位置；
      res=max(res,(i-j)/2);
  }
}
```
现在考虑两种特殊情况。
# 第一种开头有n个0；
# 第二种结尾有n个0；

第一种和第二个处理方式大致相同第一种处理时只需要判断j的值是否已经改变，若已经改变则res=max(res,(i-j)/2);;否则res=max(res,i);
第二种时候之后再结尾后面加一句res=max(res,i-j-1);减1是因为for循环中最后一个循环结束多执行了i++了一次

```
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int j=-1;
        int i=0;
        int maxc=0;
        for(i;i<seats.size();i++){
            if(seats[i]==1){
                j==-1?maxc=max(maxc,i):maxc=max(maxc,(i-j)/2);
                j=i;
            }
        }
        maxc=max(maxc,i-j-1);
        return maxc;
    }
};
```