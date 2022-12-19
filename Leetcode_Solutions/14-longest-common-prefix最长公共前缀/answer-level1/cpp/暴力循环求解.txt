### 解题思路
此处撰写解题思路
暴力循环:因为是求最长的公共前缀，所以我们只需要逐个字符串和公共前缀比较，就可以找出这个最长的公共前缀了。
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        	if(strs.empty()){
		        return "";
	        }
            string comms=strs.at(0);
            int comms_len=comms.size();
            for(int i=1;i<strs.size()&&comms_len>0;i++){
                string com_str;
                string curs=strs.at(i);
                int min_len = comms_len>curs.size()?curs.size():comms_len;
                for(int j=0;j<min_len;j++){
                    if(curs[j]==comms[j]){
                        com_str.append(1,curs[j]);
                    }else{
                        break;
                    }
                }
                comms=com_str;
                comms_len=comms.size();
            }
            return comms;
    }
};
```