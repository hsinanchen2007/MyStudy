```
class Solution {
public:
    bool oneEditAway(string first, string second) {
        //长度差>1，返回false
        if(first.size()>second.size()+1||second.size()>first.size()+1){
            return false;
        }
        int count = 0; //记录变化位置数
        int i = 0, j = 0;
        //遍历string，统计变化位数
        while(i<first.size() && j<second.size()){
            if(first[i] == second[j]) {i++; j++;} //相同后移
            else{ //不相同
                count++;
                if(count>1){return false;} //变化位数超1返回false
                //三种移项情况
                //1. first序列长，则为删除操作，跳过first当前项
                if(first.size()>second.size()){i++;} 
                //2. 一样长，则为替换操作，同时跳过
                if(first.size()==second.size()){i++;j++;}
                //3. second序列长，则为插入操作，跳过second当前项
                if(first.size()<second.size()){j++;}
            }
        }
        return true;
    }
};
