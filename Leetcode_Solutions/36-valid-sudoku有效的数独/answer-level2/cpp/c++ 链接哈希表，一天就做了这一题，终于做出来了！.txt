### 解题思路
没看大神的解题思路，都是老老实实按照自己思路来算的
![image.png](https://pic.leetcode-cn.com/1e02bb32abf5344ee1f609f3fe7a631b7e6142c925810cf432a02c80bf503602-image.png)


先遍历board，将同一数字num的坐标值(i,j)存储在hash[nums]里面：每扫描一个数字，就把它的坐标按照分离链接法存储起来，
链表的结点有两个数据域：row和col；
然后就是遍历hash，再开三个set向量：hang,lie,nine,用于分别检查行，列和九宫格是否冲突：对hash[i],遍历该位置所存储的链表，将每个结点的row值insert到hang向量，col值insert到lie向量，在insert之前检查是否已存在，若存在则说明冲突，return false；
同时在将row和col，insert的同时，计算他们的中心坐标；因为检查九宫格是否冲突，就是检查看他们的中心坐标是否相同；计算出每个坐标的中心坐标core_row,core_col后，同样把他们insert到nine向量中，若已存在则冲突，return false；
注意，每次循环都要clear掉这三个向量。
结束对hash的循环后，最后加个return true；
其中耽误了我一天时间错误的点在：我一开始声明哈希表是这样的：`vector<ListNode*> hash(9,NULL);`就是这个capacity为9，导致报错，因为数独数字是从1到9，所以容量要设为10！！


### 代码

```cpp
class Solution {
	struct ListNode{
	int row;
	int col;
	ListNode *next;
	ListNode(int r,int c):row(r),col(c),next(NULL) {}
};
	ListNode* insertListNode(ListNode* head,int row,int col){
		ListNode* temp=new ListNode(row,col);
		ListNode* p=head;
		if(head==NULL)  head=temp;
		else{
			while(p->next!=NULL) p=p->next;
			p->next=temp;
		}
		return head;
		
	}
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<ListNode*> hash(10,NULL);
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				if(board[i][j]!='.') {
					int shu=board[i][j]-'0';
					hash[shu]=insertListNode(hash[shu],i,j);  //插入数独的坐标
				}
			}
		}
		set<int> hang;  //检查行
		set<int> lie;   //检查列
		set<pair<int,int>>  nine;  //检查九宫格
		for(int i=1;i<10;i++) {
			hang.clear();    //清空set
			lie.clear();
			nine.clear();
			if(hash[i]!=NULL) {
				ListNode* p=hash[i];
				while(p!=NULL) {
					int core_row=0,core_col=0;
					if(hang.find(p->row)==hang.end()){
						hang.insert(p->row);
						//求中心
						if(p->row<=2) core_row=1;
						else if(p->row>=6) core_row=7;
						else core_row=4;
					} 
					else return false;
					if(lie.find(p->col)==lie.end()) {
						lie.insert(p->col);
						//求中心
						if(p->col<=2) core_col=1;
						else if(p->col>=6) core_col=7;
						else core_col=4;
					}
					else return false;
					if(nine.find({core_row,core_col})==nine.end()) nine.insert({core_row,core_col});
					else return false;
                    p=p->next;
					
				}
			}
		}
		return true;
    }
};
```