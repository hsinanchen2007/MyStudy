once
```cpp
class Solution {

private:
    bool verifyPostorder(const vector<int> &v, int start, int stop) { //verify [start, stop] is postorder of bt
        if (start >= stop)
            return true;
        
        int root = v[stop];
        int index = -1;
        for (int i = start; i <= stop; i++) 
            if (v[i] > root){
                index = i;
                break;
            }
        if (index == -1 || index == stop)
            return verifyPostorder(v, start, stop - 1);

        for (int i = index; i < stop; i++)
            if (v[i] < root)
                return false;
        
        return verifyPostorder(v, start, index - 1) &&
            verifyPostorder(v, index, stop - 1);
    }

public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size()-1);
    }
};
```