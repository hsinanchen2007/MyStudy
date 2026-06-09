### 解题思路
1. 由于字母日志全是小写字母，数字日志为全数字，所以判断标识符后第一个字符即可区分为何种日志
2. 由于字母日志都是有序的，所以 选择插入排序。
3. 最后合并数组内容即可

### 代码

```cpp
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::vector<string> numbersLogs;
        //numbersLogs.reserve(logs.size());
        std::vector<string> resultLogs;
        resultLogs.reserve(logs.size());
        for(int i=0;i<logs.size();i++){
            if(isNumberLog(logs[i])){//数字日志
                numbersLogs.push_back(logs[i]);
            }else{//字母日志 插入排序
                resultLogs.push_back(logs[i]);
                insertSort(resultLogs); 
            }
        }
        resultLogs.insert(resultLogs.end(),numbersLogs.begin(),numbersLogs.end());
        return resultLogs;
    }
   inline bool isNumberLog(const string& log){
        return *(log.substr(log.find(" ")+1).c_str())<'a'?true:false;
    }
    void insertSort(std::vector<string> & result){
        int len=result.size();
        if(len == 1){
            return;
        }
        string temp;
        for(int i=len-1;i>0;i--){
            int cmp=getStringValue(result[i]).compare(getStringValue(result[i-1]));
            if(cmp < 0){// 交换元素
                temp=result[i-1];
                result[i-1]=result[i];
                result[i]=temp;
            }else if (cmp==0 && getStringFlag(result[i])<getStringFlag(result[i-1])){//元素相等，判断标识符
                temp=result[i-1];
                result[i-1]=result[i];
                result[i]=temp;
                return;
            }else {// 数组有序
                return;
            }
        }
    }
   inline string getStringValue(const string&str){
        return str.substr(str.find(" ")+1);
    }
    inline  string getStringFlag(const string&str){
        return str.substr(0,str.find(" "));
    }
};
```