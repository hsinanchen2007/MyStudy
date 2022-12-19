### 解题思路
用一个整数表示一个串中字符情况,第i位=1表示该串中存在'a'+i字符

递归考虑第i个串要不要，所有要的字符串进行与操作(如果所有串不含公共元素则与之结果为0)，则将所有串进行或操作
最后考虑所选的串的长度之和

### 代码

```cpp
class Solution {
public:
    vector<int> V,T;//V存放长度 T存放串转化成整数
    void process(int index,int N,int now_value,int now_length,int &max_length){
        if(index==N){
            if(now_length>max_length) max_length=now_length;
            return ;
        }
        //不选当前串
        process(index+1,N,now_value,now_length,max_length);
        //选当前串 如果当前串如之前所有选的串之与的结果为0则有效
        if((now_value&T[index])==0){
            now_length+=V[index];
            //将现在的结果与当前串进行或操作()
            process(index+1,N,(now_value|T[index]),now_length,max_length);
        }
    }
    int maxLength(vector<string>& arr) {
        int N = arr.size();
        V.clear();
        T.clear();
        for(int i=0;i<arr.size();i++){
            int X[26]={0};
            int token = 1;
            int temp = 0;
            for(auto a:arr[i]){
                X[a-'a']+=1;
                //自己含义重复字符 去掉
                if(X[a-'a']>1){
                    token=0;
                    break;
                }
                temp|=1<<(a-'a');
            }
            if(token==0){
                N--;
                continue;
            } 
            V.push_back(arr[i].length());
            T.push_back(temp);
        }
        if(V.size()==0) return 0;
        int max_length = 0,now_length=0;
        process(0,N,0,now_length,max_length);
        return max_length;
    }
};
```