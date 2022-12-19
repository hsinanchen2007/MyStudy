1.dfs递归法

```
class Solution {
public:
    
    void dfs(int index, string S, vector<string>& output){

        if(index != S.size()){//如果还没有探索完字符串
            
            if(S[index] >= 'a' && S[index] <= 'z'){//如果当前字符是小写字母
                
                dfs(index + 1, S, output);//小写形态递归
                
                S[index] = S[index] - 'a' + 'A';
                dfs(index + 1, S, output);//大写形态递归
            }
            else if(S[index] >= 'A' && S[index] <= 'Z'){//如果当前字符是大写字母
                
                dfs(index + 1, S, output);//大写形态递归
                
                S[index] = S[index] - 'A' + 'a';
                dfs(index + 1, S, output);//小写形态递归
            }
            else{//如果是数字
                
                dfs(index + 1, S, output);//直接递归
            }
        }
        else{//如果已经探索完字符串
            
            output.push_back(S);//输出到答案中
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        
        vector<string> output;
        
        dfs(0,S,output);
        
        return output;
    }
};
```


2.bfs迭代法

```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        
        string temp;
        vector<string> output_temp,output;
        
        for(int i=0; i<S.length(); i++){
            
            if(isalpha(S[i]) != 0){//如果是字母

                if(output.size() == 0){//如果输出容器为空
                    
                    temp = tolower(S[i]);//直接插入
                    output.push_back(temp);
                    
                    temp = toupper(S[i]);
                    output.push_back(temp);
                    
                }
                else{//如果不为空
                    
                    int size = output.size();
                    
                    for(int j=0; j<size; j++){//将所指向的字符的两种形态分别和容器中的字符串结合，插入
                        
                        temp = tolower(S[i]);
                        output.push_back(output[j] + temp);
                        
                        temp = toupper(S[i]);
                        output.push_back(output[j] + temp);
                        
                        //output.erase(output.begin());
                    }
                    
                    while(size-->0)//删除使用过的字符串
                        output.erase(output.begin());
                }

            }
            else{//如果是数字
                
                if(output.size() == 0){//如果输出容器为空
                    
                    temp = S[i];
                    output.push_back(temp);
                }
                else{
                    
                    int size = output.size();
                    
                    for(int j=0; j<size; j++){
                        
                        temp = S[i];
                        output.push_back(output[j] + temp);
                        
                        //output.erase(output.begin());
                    }
                    
                    while(size-->0)
                        output.erase(output.begin());
                }
            }
        }
            

        
        
        return output;
    }
};
```
