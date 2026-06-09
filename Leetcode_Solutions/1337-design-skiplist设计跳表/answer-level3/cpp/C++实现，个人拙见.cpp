看没有C++的题解，我就简略写一个，另外我看其他的题解好像有一些并没有真正理解跳表的精神所在。

执行用时 :76 ms, 在所有 cpp 提交中击败了91.67%的用户
内存消耗 :28.3 MB, 在所有 cpp 提交中击败了100.00%的用户

**1.首先定义节点SkipNode,他应该具有以下成员：**
int val:节点的值；
int level:节点的等级；
SkipNode** next:用于保存下一节点的指针的数组；
*
这里着重讲一下next：
由于跳表中每个节点有自己的等级（level），所以在跳到下一个节点的时候，需要根据当前等级决定跳到哪一个节点，故需要根据level创建动态数组来保存下一节点的指针。*

**2.然后定义SkipList，其成员有：**
Listlevel:用于保存当前跳表中的最高节点等级，这样在操作时可以从这个等级开始操作。
head:创建一个SkipList时，它应该有一个head并且其保存的next数组全都指向nullptr。

**3.完成了以上的结构后，剩下的就是定义增删改查的函数了，这部分就相对简单了，可以看代码进行理解，故此不再赘述。**

唯一有趣的地方是getlevel函数：
由于跳表应随着节点数的增加来增加listlevel，
如果已经有现成的跳表，需要指定每个节点的登记，一个理想的做法是用类似二分法的做法，将1/2处定为最高等级节点，1/4和3/4处定位次高等级节点...依此类推。

但由于跳表存在增删操作，所以不能采用这种方法，那么另一种方法就是在每次产生节点时随机定出该节点的等级，如果遵循二分法的精神，则level0的节点数应该占总节点数的1/2，level1的节点数占总节点数的1/4...这就是getlevel函数的核心机制：rand()<RAND_MAX/2
当然，也可以根据实际情况把2改成其他数字，但大多数情况下2是最佳选择。

```
const int MAX_LEVEL=10;
class SkipNode{
public:
    int val;
    int level;
    SkipNode** next;
    SkipNode(int v,int l){
        val=v;
        level=l;
        next=new SkipNode*[l+1]();
    }
};

class Skiplist {
private:

public:
    SkipNode* head;
    int Listlevel;
    Skiplist() {
        head=new SkipNode(INT_MIN,MAX_LEVEL);
        Listlevel=0;
    }
    int getlevel(){
        int lev=0;
        while(lev<MAX_LEVEL && lev<=Listlevel && rand()<RAND_MAX/2){
            ++lev;                      //等级为lev的节点出现的概率为1/2^lev
        }
        if(Listlevel<lev)++Listlevel;   //如果新节点等级高于跳表等级，则跳表等级加一
        return lev;
    }
    bool search(int target) {
        SkipNode* sn=head;
        int ll=Listlevel;
        while(ll>=0){
            while(sn->next[ll]!=nullptr && sn->next[ll]->val<=target)sn=sn->next[ll];
            --ll;
        }
        if(sn->val==target)return true;
        return false;
    }
    
    void add(int num) {
        //if(search(num))return; //一开始我没注意可以增删重复数字，所以加了这一行
        SkipNode* sn=head;
        int lev=getlevel();
        int ll=Listlevel;
        SkipNode* nsn=new SkipNode(num,lev);
        while(ll>=0){
            while(sn->next[ll]!=nullptr && sn->next[ll]->val<num)sn=sn->next[ll];
            if(ll<=lev){
                nsn->next[ll]=sn->next[ll];
                sn->next[ll]=nsn;
            }
            --ll;
        }
    }
    
    bool erase(int num) {
        if(!search(num))return false;
        SkipNode* sn=head;
        SkipNode* dsn;
        int ll=Listlevel;
        while(ll>=0){
            while(sn->next[ll]!=nullptr && sn->next[ll]->val<num)sn=sn->next[ll];
            if(ll==0)dsn=sn->next[ll];
            if(sn->next[ll]!=nullptr && sn->next[ll]->val==num){
                sn->next[ll]=sn->next[ll]->next[ll];
            }
            --ll;
        }
        if(dsn->level==Listlevel){              //如果删除的节点等级为最高等级节点，
                                                //则检查是否为唯一最高等级节点,
                                                //如果是，那么跳表等级减一。
            if(head->next[Listlevel]==nullptr)--Listlevel;
        }
        return true;
    }
};
```
