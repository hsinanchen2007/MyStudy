![QQ图片20200310204949.png](https://pic.leetcode-cn.com/c62f87863cdfa6ec9acdf6d87c573b7d386030ac10952e3aa5db82e2de7333c2-QQ%E5%9B%BE%E7%89%8720200310204949.png)

类似于层次遍历的思路，先取出某层的第一个元素，用len来标记一层剩下的长度，统计每个数字连续出现的次数，然后入队，注意两种情况：1.某层最后为单一的某个元素如XX1，这时没必要再进行下次循环；  2.某层最后为连续的几个数，如XX1111
```
class Solution {
public:
    string countAndSay(int n) {
        queue<int> qu;
        if(n==1)return "1";
        if(n==2)return "11";
        qu.push(1);
        qu.push(1);      
        string ans="";
        for(int i=2;i<n;i++){
            int num =qu.front();
            qu.pop();
            int len=qu.size();
            int count=1;
            while(len>=0){
                if(qu.front()==num){
                   count++; 
                   len--;
                   qu.pop();
                   //最后的部分为连续相等的几个数，如XX1111
                   if(len==0){
                       qu.push(count);
                       qu.push(num);
                       break;
                   }
                }
                else{
                    qu.push(count);
                    qu.push(num);
                    if(len>0){
                        num=qu.front();
                        count=1;
                        len--;
                        qu.pop();
                        //最后的部分为单独的一个数，如XX1
                        if(len==0){
                            qu.push(count);
                            qu.push(num);
                            break;
                        }
                    }else break;
                    
                }
            }
        }

        while(!qu.empty()){
            ans+=to_string(qu.front());
            qu.pop();
        }
        return ans;
    }
};
```
