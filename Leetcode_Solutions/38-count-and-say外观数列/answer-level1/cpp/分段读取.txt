### 解题思路
第一次解答：）
反复读取，次数为n；
待读取段为n，读取结果为ans；
读取一段获得内容以及个数存储。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string ans;
        if(n<=0) return ans;
        string now;
        ans={'1'};
        for(int i=1;i<n;i++){
            //重复读取次数
            now=ans;
            //整体读取
            int len=now.size();
            ans={};//存储清空；
            for(int m=0;m<len;){
                //分段
                int count=0;//段长
                char temp=now[m];//段的内容
                while(temp==now[m]){//段的内容与当前内容相符
                    count++;
                    m++;
                }
                //不符合，将结果放入存储处
                ans+=char(count+48);
                ans+=temp;
            }
        } 
        return ans;
    }
};
```