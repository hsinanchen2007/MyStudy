执行用时 : 8 ms, 在Restore IP Addresses的C++提交中击败了89.58% 的用户

内存消耗 : 9.1 MB, 在Restore IP Addresses的C++提交中击败了13.90% 的用户
```
class Solution {
private:
    bool isValidIP(const string & s)
    {
        if(s.empty()||s.size()>3||(s[0]=='0'&&s.size()>1))return false;
        int tmp=stoi(s);
        if(tmp>=0&&tmp<=255)return true;
        return false;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.size()<4||s.size()>12)return ret;
        vector<int> tmp;
        vector<int> copy;
        int size=s.size();
        //第一个数代表起始位置，第二个数代表子串长度
        tmp.push_back(0);
        tmp.push_back(1);
        stack<vector<int>> ip_stack;
        stack<vector<int>> tmp_stack;
        ip_stack.push(tmp);
        while(!ip_stack.empty())
        {
            if(ip_stack.size()<4)
            {//栈内数据补齐至4
                copy=ip_stack.top();
                tmp=copy;
                tmp[0]=tmp[0]+tmp[1];
                //printf("add %d size %d\n",tmp[0],ip_stack.size());
                if(tmp[0]+1>size)break;
                //补齐长度从1开始
                tmp[1]=1;
                ip_stack.push(tmp);
            }
            else
            {
                tmp=ip_stack.top();
                if(tmp[0]+tmp[1]==size)
                {
                    ip_stack.pop();
                    string save=s.substr(tmp[0],tmp[1]);
                    bool change=false;
                    bool change_start_found=tmp[1]>1?true:false;
                    for(int i=0;i<3;i++)
                    {
                        tmp=ip_stack.top();
                        ip_stack.pop();
                        save=s.substr(tmp[0],tmp[1])+"."+save;
                        if(!change_start_found)
                        {
                            change_start_found=tmp[1]>1?true:change_start_found;
                            continue;
                        }
                        bool push_flag=true;
                        if(!change)
                        {
                            if(tmp[1]<3)
                            {
                                tmp[1]++;
                                if(isValidIP(s.substr(tmp[0],tmp[1])))change=true;
                                else
                                {//代表此位不可变且不能再次进入栈,之前进栈的元素全部出栈
                                    while(!tmp_stack.empty())tmp_stack.pop();
                                    push_flag=false;
                                }
                            }
                            else push_flag=false;
                        }
                        if(push_flag)tmp_stack.push(tmp);
                    }
                    //cout<<save<<endl;
                    ret.push_back(save);
                    while(!tmp_stack.empty())
                    {
                        ip_stack.push(tmp_stack.top());
                        tmp_stack.pop();
                    }

                }
                else
                {
                    while(!ip_stack.empty())
                    {
                        tmp=ip_stack.top();
                        ip_stack.pop();
                        if(tmp[1]<3)
                        {
                            tmp[1]++;
                            //printf("add %d %d %d\n",tmp[0],tmp[1],ip_stack.size());
                            if(isValidIP(s.substr(tmp[0],tmp[1])))
                            {
                                ip_stack.push(tmp);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};
```