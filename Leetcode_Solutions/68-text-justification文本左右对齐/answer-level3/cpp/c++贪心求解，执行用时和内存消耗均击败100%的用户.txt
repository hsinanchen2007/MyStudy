### 解题思路
![image.png](https://pic.leetcode-cn.com/5b11b55ce3ea078a3f7c0be9ca0a38ba3f3d088ef4a729e82c4452006dee15ca-image.png)
使用贪心算法，一行中尽可能多的放置单词
**本题的难点就是确定每两个单词之间需要插入多少个额外的空格**
当该单词不能放入该行时，首先计算出改行需要补充blocknum个空格，假设该行有lineNum个单词，那么需要补充空格的地方有lineNum-1个，这里必须从后往前计算每个位置需要补充的空格数，因为按照要求如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
每个位置补充的空格数为blocknum/leftWord，leftWord为当前位置左边的单词个数，每计算完一个位置的单词个数，blocknum需要减去该位置补充的单词数
按照以上策略计算每个位置补充的空格个数才能够满足题设要求：尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
### 代码

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string s="";
        int cur_length=0;//当前行已经填补的字母个数
        int lineNum=0;//一行中单词的个数
        int i=0;
        while(i<words.size()){
            if(cur_length+words[i].length()<=maxWidth){//当该行可以放置下一个单词时
                cur_length+=words[i].length();//当前长度加上单词的长度
                s+=words[i];
                lineNum++;//单词个数+1
                if(cur_length<maxWidth){
                    cur_length++;
                    s+=" ";
                }
                else if(cur_length==maxWidth){//当前长度正好=maxWidth
                    ans.push_back(s);//保存
                    s="";
                    cur_length=0;
                    lineNum=0;//清空参数，重新记录
                }
                i++;
            }
            else{//否则
                cur_length--;
                s.erase(s.end()-1);//去除字符串s末尾的空格
                int blocknum=maxWidth-cur_length;//计算要补全多少个空格
                if(lineNum==1){//如果一行只有一个单词
                    string blockstr(blocknum,' ');
                    s+=blockstr;
                    ans.push_back(s);//直接在s后补齐blocknum个空格
                    lineNum=0;
                    cur_length=0;
                    s="";//清空参数，重新记录
                }
                else{//计算每两个单词之间需要补充的空格个数
                    vector<int> blocks(lineNum-1,0);
                    int j=lineNum-2;
                    for(;j>=0;j--){
                        blocks[j]=blocknum/(lineNum-1);
                        blocknum-=blocks[j];
                        lineNum--;
                    }//计算每个位置补充的空格个数，从后往前计算
                    int cur=0,wordpos=i-blocks.size()-1;
                    //wordpos为当前行单词的起始位置，cur为补充空格的位置
                    for(j=0;j<blocks.size();j++){
                        cur+=(words[wordpos].length()+1);
                        string bstr=string(blocks[j],' ');
                        s.insert(cur,bstr);
                        cur+=blocks[j];
                        wordpos++;
                    }
                    ans.push_back(s);
                    lineNum=0;
                    cur_length=0;
                    s="";//清空参数，重新记录
                }
                
            }
        }
        if(cur_length!=0){//若存在未记录的文本
            string blockstr(maxWidth-cur_length,' ');
            s+=blockstr;
            ans.push_back(s);
        }
        return ans;
    }
};
```