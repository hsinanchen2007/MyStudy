因为是从小到大排序好的有序数组，
故考虑用二分法求解
```
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int a = 0;
        int b = letters.size()-1;
        int tem;
        while(b-a!=1){
            tem = (a+b)/2;
            //if( letters[tem]==target  ) {}//return letters[++tem];
            if(letters[tem]<=target) a =tem;
            else b =tem;          
        }
        if( b==letters.size()-1&&letters[b]<target ) return letters[0];//只剩最后两个
        if( a=0&&letters[a]>target ) return letters[0];//只剩头两个
        if(letters[a]<=target&&letters[b]>target) return letters[b];//在中间
        //if( letters[a]>target ) return letters[a];
        return letters[a];

    }
};
```
