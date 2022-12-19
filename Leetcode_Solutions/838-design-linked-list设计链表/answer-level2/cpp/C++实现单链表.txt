本题设计链表功能主要有三种类型，1、根据索引得到相应位置上节点的值。2、插入节点。3、删除节点。
三个功能都涉及到查找，因此我可以实现一个查找接口findpre，根据题目要求，这个函数返回索引位置的前一个位置。
实现功能1：利用findpre接口找到当前位置的前一个时直接调用next引用。
实现功能2：引入m_head以及m_tail两个对外不可见节点，方便将边界情况统一为一般情况。
实现功能3：与功能1类似。

```
struct MyListNode
{
	int data;
	MyListNode* next;
	MyListNode(int left=-1, MyListNode* right=nullptr):data(left), next(right){}
};


class MyLinkedList {
public:
	MyLinkedList():m_size(0){
		m_head=new MyListNode;
		m_tail=new MyListNode;
		m_head->next=m_tail;//初始化外部不可见节点，后续节点插入头尾之间
	}
	/**析构函数
	~MyLinkedList()
	{
		MyListNode* p=m_head->next;
		for(int i=0; i<m_size; i++)
		{
			MyListNode* p2=p;
			p=p->next;
			delete p2;
		}
		delete m_head;
		delete m_tail;
	}*/
    int get(int index) {
		if(index<0||index>m_size-1)//入口参数合法性检验
			return -1;
		MyListNode* p=findpre(index);
		return p->next->data;
    }
    
    void addAtHead(int val) {
		insert(0,val);//三个插入接口统一成一般形式
    }
    
    void addAtTail(int val) {
		insert(m_size,val);
    }
    
    void addAtIndex(int index, int val) {
		if(index>m_size)    //入口参数调整取值0~链表长度
			return;
		if(index<0)
			index=0;
        insert(index, val);
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>m_size-1) return;	//入口参数合法性检验
		MyListNode* p=findpre(index);
		MyListNode* curNode=p->next;
		p->next=p->next->next;
        m_size--;
		delete curNode;
	}
private:
	MyListNode* findpre(int index)
	{
		MyListNode* p=m_head;
		while (index!=0)
		{
			p=p->next;
			index--;
		}
		return p;
	}
	void insert(int index, int val)
	{
		MyListNode* preNode=findpre(index);
		MyListNode* afterNode=preNode->next;
		MyListNode* currNode= new MyListNode;
		preNode->next=currNode;
		currNode->next=afterNode;
		currNode->data=val;
		m_size++;
	}
	MyListNode* m_head; 
	MyListNode* m_tail;
	int m_size;
};


```
