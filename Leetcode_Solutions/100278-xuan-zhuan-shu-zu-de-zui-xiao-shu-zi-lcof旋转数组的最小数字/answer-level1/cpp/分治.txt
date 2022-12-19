```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        return lalala(numbers,0,numbers.size()-1);
    }

    int lalala(const vector<int>& numbers,int left,int right){
        if(numbers[left]<numbers[right]){
            return numbers[left];
        }
        if(left==right){
            return numbers[left];
        }
        int mid=(left+right)/2;
        return min(lalala(numbers,left,mid),lalala(numbers,mid+1,right));
        
    }
};
```
