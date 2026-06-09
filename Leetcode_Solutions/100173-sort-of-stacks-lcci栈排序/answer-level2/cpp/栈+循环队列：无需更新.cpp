在阅读了评论区的双栈惰性更新后使用栈+循环队列来实现无需更新。
使用循环队列使得得到栈顶和栈底元素都十分方便且减小了内存的占用。
```
class SortedStack {
public:
    int main_stack[5005],help_stack[5005],main_p=0,help_l=0,help_r=0;
    SortedStack() {

    }

    void push(int val) {
        if(main_p==0&&help_l==help_r){main_stack[main_p++]=val;}
        else if(main_p==0||val<main_stack[main_p-1]){
            while(help_l!=help_r&&help_stack[help_r-1]>val){
                main_stack[main_p++]=help_stack[help_r-1];
                help_r--;
            }
            help_stack[help_r++]=val;
        }
        else{
            while(main_p&&main_stack[main_p-1]<val){
                help_stack[help_r++]=main_stack[main_p-1];
                main_p--;
            }
            main_stack[main_p++]=val;
        }
    }
    
    void pop() {
        if(help_l!=help_r){
            help_l=(help_l+1)%5005;
        }
        else if(main_p){
            main_p--;
        }
    }
    
    int peek() {
        int res=-1;
        if(help_l!=help_r){
            res=help_stack[help_l];
        }
        else if(main_p){
            res=main_stack[main_p-1];
        }
        return res;
    }
    
    bool isEmpty() {
        if(help_l==help_r&&main_p==0)return true;
        return false;
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
```
![image.png](https://pic.leetcode-cn.com/48e7d50e9a4e256b68bcc2112a96ef1971e71d894962253462efc0434c2395ac-image.png)

