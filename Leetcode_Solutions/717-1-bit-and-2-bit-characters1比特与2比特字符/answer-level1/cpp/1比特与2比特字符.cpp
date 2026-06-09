直接遍历整个数组
在剩余比特数>=2时，逢1加1。
当比特数只剩下1到2个的时候，由于总是由0结束，所以我们只需考虑10这种情况会返回false。
```
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //1 <= len(bits) <= 1000
        //bits[i] 总是0 或 1
        
        //末尾的情况：0，00，10
        for(int i = 0;i != bits.size();i++){
            if(i >= bits.size() - 2 && bits[i] == 1)
                return false;
            if(bits[i] == 1)
                i++;//逢1加1
        }
        return true;
    }
};
```
