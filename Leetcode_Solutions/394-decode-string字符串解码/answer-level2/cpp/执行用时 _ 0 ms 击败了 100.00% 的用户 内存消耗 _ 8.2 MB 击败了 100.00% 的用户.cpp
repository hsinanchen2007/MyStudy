
想法：先找到']'，再往回找到整个[YYY]，翻倍后插入。
![IMG_0303.JPG](https://pic.leetcode-cn.com/f6d7accb45a090a38c4909b4d57f5db6f4155365d49920a188e643b71c94d123-IMG_0303.JPG)

```
class Solution {
public:
    string decodeString(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                int j=i;
                while(s[j]!='[') j--;
                int times_start=j-1;
                while(times_start>=0&&s[times_start]>='0'&&s[times_start]<='9') times_start--;
                times_start++;
                int times=0;
                for(int k=j-1;k>=times_start;k--){
                    times+=(s[k]-'0')*pow(10,j-1-k);
                }
                string temp_str;
                temp_str.insert(temp_str.begin(),s.begin()+j+1,s.begin()+i);
                s.erase(s.begin()+times_start,s.begin()+i+1);
                for(int k=0;k<times;k++){
                    s.insert(times_start,temp_str);
                }
                i=times_start+times*(i-j-1)-1;
            }
        }
        return s;
    }
};
```
