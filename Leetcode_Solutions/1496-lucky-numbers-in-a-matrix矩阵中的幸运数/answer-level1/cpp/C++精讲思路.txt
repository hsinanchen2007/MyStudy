拿到题目先想着把每列的最大值和每行找出来，分别用col和vec来保存，col找每列最大值的时候可以采用滚动数组的思维，让他自己一行一行的翻着去找。
然后用一个bool类型表示开关，初始为false，开始找这行的最小值，找到之后拿这个数字和他所在的列的最大值进行比较，如果小于列最大值就从vec中删掉，这就是num的一个小妙用，记住vec的下标的位置，--num是因为用了erase，少了一个元素，后面还有一个++num，-1+1相当于没有变动，如果找到这行的最小值bool类型就立马设置为true直接退出循环。

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>vec;
        vector<int>col(matrix[0].size(),0);
        for(size_t i=0;i<matrix.size();++i){
            int min=INT_MAX;
            for(size_t j=0;j<matrix[i].size();++j){
                if(matrix[i][j]>col[j])col[j]=matrix[i][j];//找到每列最大的值
                if(matrix[i][j]<min)min=matrix[i][j];
            }
            vec.emplace_back(min);//把每一行的最小值装进去
        }
        int num=0;//表示第几行
        for(size_t i=0;i<matrix.size();++i){
            bool ok=false;//控制开关
            for(size_t j=0;j<matrix[i].size();++j){
                if(matrix[i][j]==vec[num]){//i表示实际的第几行，num表示vec的下标
                    if(vec[num]<col[j]){//j表示列的,num表示行的,小于就从vec中删掉
                        vec.erase(vec.begin()+num);
                        --num;
                        ok=true;
                    }
                }
                if(ok)break;
            }
            ++num;
        }
        return vec;
    }
};