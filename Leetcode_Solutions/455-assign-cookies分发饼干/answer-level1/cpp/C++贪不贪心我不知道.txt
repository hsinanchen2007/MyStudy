算法贪不贪心我不知道，反正排序后，
只要我当前的饼干能够满足当前需求最小的小孩我就把饼干给他，
然后拿下一个更大的饼干，找寻是否有满足饭量的小孩，
有就给他，没有就拿下一个饼干再找小孩
```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int sum=0;//表示满足的小孩
        int i= 0;//表示小孩
        for(int j=0;j<s.size();++j){
            //if(i>=g.size()) return sum;
            while(i<g.size()){
                if(s[j]>=g[i]) {++sum;++i;break;}
                else break;
            }
        }
        return sum;
    }
};
```
