一、判断前缀是否满足UTF8编码，即一字节前有多少个1，cnt > 4时不满足条件.
二、直接循环判断（状态机模型）
```c++
class Solution {
public:
    inline int GetUTFType(int n) {
        const unsigned mask = 0x80;
        int cnt = 0;
        for(cnt = 0; cnt <= 5; ++cnt) {
            if(!((mask >> cnt)&(unsigned)n)) return cnt;
        }
        return cnt;
    }

    bool validUtf8(vector<int>& data) {
        auto it = data.begin();
        int left = 0;
        while (it != data.end()) {
            int status = GetUTFType(*it);
            switch (status) {
                case 0:
                    it++;
                    break;
                case 1:
                    return false;
                case 2:
                case 3:
                case 4:
                    left = status - 1;
                    it++;
                    for(int i = 0; i < left; ++i) {
                        if(it == data.end()) return false;
                        if(1 != GetUTFType(*it)) return false;
                        it++;
                    }
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
};
```