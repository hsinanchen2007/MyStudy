```
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len=bits.size();
        if(bits[len-1]==1) return false;  //最后一位是1,false
        for(int i=0;i<len;i++){
            if(i==len-1) return true;       //最后一位是0，就true（这里由于已经排除了最后一位是1的情况，只要可以到最后一位，就是对的）
            if(bits[i]==1&&i<len-1) i++; //其实10和11是一样的，都占两位，根本没有其他情况
        }
        return false;
    }
};
```