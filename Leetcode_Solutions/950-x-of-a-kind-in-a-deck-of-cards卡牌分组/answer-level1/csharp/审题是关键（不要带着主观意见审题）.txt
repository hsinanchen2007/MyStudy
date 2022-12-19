### 解题思路
在读懂题目之后就知道它给的测试用例的结果是错误的。显然X选1是肯定成立的，现在就是从2开始判断后面有没有可以成立的。用字典保存每个键值之间的关联，然后从2开始计算符合两个要求的结果就可以了。

### 代码

```csharp
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        Dictionary<int,int> dic = new Dictionary<int,int>();
        for(int i =0;i<deck.Length;i++){
            if(!dic.ContainsKey(deck[i])){
                dic.Add(deck[i],1);
            }
            else{
                dic[deck[i]]++;
            }
        }
        
        for(int i = 2;i<10000;i++){
            if(deck.Length % i == 0){
                bool tag = true;
                for(int j =0;j<deck.Length;j++)
                {
                    if((dic[deck[j]] % i) != 0){
                        tag = false;
                        break;
                    }
                }
                if(tag == true){
                    return true;
                }
            }
            else{
                continue;
            }
        }
        return false;
    }
}
```