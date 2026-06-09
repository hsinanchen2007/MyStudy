根据队列queue
```
class Solution {
public:
    string countAndSay(int n) {
        string res="";
        int count=0,tmp=1,bt=0,qsize=1;
        queue<int> que;
        que.push(1);
        for(int i=2;i<=n;i++){
            while(qsize>0){
                if(que.front()==tmp) count++;
                else{
                    que.push(count);
                    que.push(bt);
                    count=1;
                    tmp=que.front();   
                }
                bt=que.front(); 
                que.pop();
                qsize--;
            }
            que.push(count);
            que.push(bt);
            tmp=que.front(); 
            count=0;
            qsize=que.size();    
        }
        while(!que.empty()){
            res +=to_string(que.front());
            que.pop();
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/139ecc2e1ddb1b1225323b8a557aff45e6b2e68b4689162fd2cc3f94918ab1ae-image.png)


