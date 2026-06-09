### 解题思路
![TIM截图20200223233714.png](https://pic.leetcode-cn.com/effc99f4ab284a325eefd5ce23ba2846ab557ca899e84a563b6e741d8b45de2d-TIM%E6%88%AA%E5%9B%BE20200223233714.png)
寻找每个结点的父节点，相同的父节点最多出现两次，没有父节点的结点只有一个
### 代码

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
            vector<int> father;
            for(int i=0;i<n;i++)
            {
                father.push_back(-1);
            }
            for(int i=0;i<n;i++)
            {
                if(leftChild[i]!=-1)
                {
                    if(father[leftChild[i]]==-1)
                    {
                        father[leftChild[i]]=i;
                    }
                    else
                    {
                        for(int i=0;i<n;i++)
                        {
                            cout<<father[i]<<endl;
                        }
                        return false;
                        break;
                    }
                }
                if(rightChild[i]!=-1)
                {
                    if(father[rightChild[i]]==-1)
                    {
                        father[rightChild[i]]=i;
                    }
                    else
                    {
                        cout<<1<<endl;
                        return false;
                        break;
                    }
                }
            }
            int k=0;
            vector<int> who,times;
            for(int i=0;i<n;i++)
            {
                if(father[i]==-1)
                {
                    k=k+1;
                }
                if(who.size()==0)
                {
                    who.push_back(father[i]);
                    times.push_back(1);
                }
                else 
                {
                    vector<int>::iterator iter;
                    iter=find(who.begin(),who.end(),father[i]);
                    if(iter!=who.end())
                    {
                        times[iter-who.begin()]++;
                        if(times[iter-who.begin()]>2)
                        {
                            cout<<2<<endl;
                            return false;
                            break;
                        }
                    }
                    else
                    {
                        who.push_back(father[i]);
                        times.push_back(1);
                    }
                }

            }
            if(k!=1)
            {
                return false;
            }
            return true;
    }
};
```