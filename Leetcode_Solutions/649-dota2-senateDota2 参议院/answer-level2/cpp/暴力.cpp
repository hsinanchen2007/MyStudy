### 解题思路

直接模拟就行了，反正是循环来的，禁前面和后面无所谓，直到只剩一方阵营为止
### 代码

```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        string temp=senate;
        int m=0,n=0;
        do{
            senate=temp;//更新这一轮的参会者
            temp.erase(0);
            for(char c : senate){
                if(c=='R'){
                    if(!n){//这个人进入下一轮
                        temp+=c;
                        m++;
                    }
                    else n--;//这个人在这一轮被禁了
                }
                else{
                    if(!m){//这个人进入下一轮
                        temp+=c;
                        n++;
                    }
                    else m--;//这个人在这一轮被禁了
                }
            }
        }while(temp!=senate);
        return senate[0]=='R'?"Radiant":"Dire";
    }
};
```