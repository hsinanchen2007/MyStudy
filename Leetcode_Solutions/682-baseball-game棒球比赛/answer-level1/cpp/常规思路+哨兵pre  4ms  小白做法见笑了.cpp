class Solution {
public:
    int calPoints(vector<string>& ops) {
        int pre,tmp,sum=0;
        stack<int> sk;
        sk.push(0);//设置哨兵
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"&& !sk.empty()) {
                sk.pop(); //将需Clear的得分出栈
                tmp=sk.top(); //暂存Clear后的栈顶(原top)，以备下一步寻找pre
                sk.pop(); //将原top出栈，pre=此时top                                
            }
            else if(ops[i]=="D")    tmp=2*sk.top(); 
            else if(ops[i]=="+") tmp=pre+sk.top();
            else tmp=atoi(ops[i].c_str());
            if(!sk.empty()) pre=sk.top(); //时刻更新pre
            sk.push(tmp);
        }
        //入栈完毕，求和
        while(!sk.empty()){
            sum=sum+sk.top();
            sk.pop();
        }
        return sum;
    }
};