### 解题思路
我是从分治区点进来的。。
看完题之后下意识是回溯，朝分治的方向想了半天也没有头绪，来题解区看了一眼全是回溯。。。EXM？？？

普通dfs
传递的时候考虑当前正在执行的op操作，加减只往前考虑一个即可，乘的话把连乘当作整体，用multi表示，并向前考虑第一个不是乘法操作的op操作，用llop表示。


好吧我只想想来吐槽一下把他划到了分治区=m=

### 代码

```cpp
class Solution {
public:
    string num="";
    int target;
//啥也不干：0 +:1 -:2 *:3
    string op[4] {"","+","-","*"};
    vector<string>result;

    void dfs(int site,int lastop, long long lastnum, int llop, long long multi, long long sum,string lstring){
        /*cout<<"num["<<site<<"] = "<<num[site]<<endl;
        cout<<"lstring :"<<lstring<<endl;
        cout<<"lastop = "<<op[lastop]<<", lastnum = "<<lastnum<<", llop = "<<op[llop]<<",multi = "<<multi<<", sum = "<<sum<<endl;
        */
        if(site>=num.size()-1){
            if(lastop == 3){
                if(llop == 0){
                    if(lastnum != -1)multi /= lastnum;
                    lastnum = ((lastnum==-1)?0:lastnum) * 10+num[site]-'0';
                    multi *= lastnum;
                    sum = multi;
                }
                else{
                    if(llop == 1) sum -= multi;
                    else sum += multi;
                    if(lastnum != -1)multi /= lastnum;
                    lastnum = ((lastnum==-1)?0:lastnum) * 10+num[site]-'0';
                    multi *= lastnum;
                    if(llop == 1) sum += multi;
                    else sum -= multi;
                }
            }
            else{
                if(lastop == 0){
                    sum = sum * 10 + num[site]-'0';
                }
                else{
                    if(lastop == 1){
                        //+
                        sum -= ((lastnum == -1)?0:lastnum);
                    }
                    else{
                        sum += ((lastnum == -1)?0:lastnum);
                    }
                    lastnum = ((lastnum == -1)?0:lastnum )*10+num[site]-'0';
                    if(lastop == 1) sum += lastnum;
                    else sum -= lastnum;
                }
            }

            if(sum == target){
                lstring += num[site];
                result.push_back(lstring);
            }
            return ;
        }

        if(lastop!=3){
            //上一个op不是乘法

            if(lastop == 1){
                //+
                sum -= (lastnum==-1)?0:lastnum;
                lastnum = ((lastnum==-1)?0:lastnum)*10 + num[site]-'0';
                sum += lastnum;
            }
            else if(lastop == 0){
                sum = sum*10 + num[site]-'0';
                lastnum = sum;
            }
            else{
                sum += ((lastnum==-1)?0:lastnum);
                lastnum = ((lastnum==-1)?0:lastnum)*10+num[site]-'0';
                sum -= lastnum;
            }
            for(int i = (lastnum==0)?1:0 ;i < 4;i++){
                    if(i==0){
                        //不加运算符
                        dfs(site+1,lastop,lastnum,llop,multi,sum,lstring+num[site]+op[i]);
                    }
                    else if (i!=3){
                        dfs(site+1,i,-1,lastop,multi,sum,lstring+num[site]+op[i]);
                    }
                    else{
                        dfs(site+1,i,-1,lastop,lastnum,sum,lstring+num[site]+op[i]);
                    }
                }
        }
        else{
            //是乘法
            if(llop==1){
                //llop is +
                sum -= multi;
                if(lastnum>0) multi/=lastnum;
                lastnum = ((lastnum==-1)?0:lastnum)*10+num[site]-'0';
                multi *= lastnum;
                sum += multi;
            }
            else if(llop == 0){
                if(lastnum>0) multi/=lastnum;
                lastnum = ((lastnum==-1)?0:lastnum)*10+num[site]-'0';
                multi *= lastnum;
                sum = multi;
            }
            else{
                sum += multi;
                if(lastnum>0) multi/=lastnum;
                lastnum = ((lastnum==-1)?0:lastnum)*10+num[site]-'0';
                multi *= lastnum;
                sum -= multi;
            }
            for(int i = (lastnum==0)?1:0 ;i < 4 ;i++){
                if(i == 0){
                    //啥也不干
                    dfs(site+1,lastop,lastnum,llop,multi,sum,lstring+num[site]+op[i]);
                }
                else if(i == 3){
                    //继续乘
                    dfs(site+1,i,-1,llop,multi,sum,lstring+num[site]+op[i]);
                }
                else{
                    //不乘了
                    dfs(site+1,i,-1,lastop,multi,sum,lstring+num[site]+op[i]);
                }
            }
        }
    }
    vector<string> addOperators(string Num, int Target) {
        num = Num;
        if(num.size() == 0)return result;
    
        target = Target;
        dfs(0, 0, -1, 0, 0, 0,"");
        return result;
    }
};
```