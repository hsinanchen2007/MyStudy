一个轮子，红黑树的实现，相当于是对stl的set，map的扩展吧，增加了一个size域，可以在O(logn)的时间内查询小于大于某个key的节点数量。接口我已经给出来了。最近遇到了好几道都需要动态插入数据并且排序的题目，但是set只给了个upper_bound和lower_bound接口，查询操作给的太少，所以这个轮子常备着还是很有必要的。

ps:双周竞赛题，说的是查询长度为k而且平均值大于某个阈值的子数组数量，我当时没认真看，以为是所有的长度的子数组，然后自然而然就想到了求每一个数减去阈值之后的新数组的前缀和，然后对于sum[j]，只要查询前面有多少个sum[i]小于等于sum[j]即可，自然而然就想到要对前面的数据排序，然后二分查询，但是如何动态维持前面的数据时有序的呢？如果使用普通的插入排序岂不是要O(n)，所以平衡的二叉排序树就出现了。
```
#pragma once
#include<iostream>
/*	没办法，stl自带的set和map的扩展功能太少了，比如说搜索小于等于某个key的总数就无法扩展，所以还是得回来这里用 原版的红黑树（平衡的二叉搜索树） 
	原来实验做的是没有相同键的（set ,map)但是很多时候得弄一个兼容multiset和multimap的出来，所以说还是得修改修改。

*/
using namespace std;
template<class Key,class Value>
class RBTree
{
private:
	enum Color
	{
		red,
		black
	};
	struct RBTree_Node
	{
		Key key;
		Color color;
		Value value;//卫星数据 扩展数据什么的 比如size ，比如 区间 
		size_t size;
		
		RBTree_Node*p;
		RBTree_Node*lchild;
		RBTree_Node*rchild;

		RBTree_Node(Key k, Value v) :
			p(NULL),
			lchild(NULL),
			rchild(NULL),
			color(red),
			key(k),
			value(v),
			size(1)
		{}
	};

	typedef RBTree_Node Node;
public:
	
	RBTree()
	{
		//这里还是有一丢丢问题
		NIL= new Node(-1, 0);//还是设定一个空指针方便操作 要不然要一直判断是不是空指针
		NIL->color = black;
		NIL->size = 0;
		key_count = 0;
		root = NIL;
	}
	~RBTree()
	{
		free(root);
		delete NIL;
	}

	size_t count_less(const Key&key)
	{
		return count_less(root,key);
	}
	size_t count_less_equal(const Key&key)
	{
		return root->size-count_greater(root, key);//总数减去大于的就是小于等于的
	}
	size_t count_less(Node*r, Key key)//这里不对，size是没错，但是，左旋右旋调整之后相等节点不一定还在左边，也可能走到右边去
	{
		if (r == NIL)
			return 0;
		else if (key <= r->key)
			return count_less(r->lchild, key);
		else
			return count_less(r->rchild, key) + r->lchild->size + 1;
	}
	size_t count_greater(const Key&key)
	{
		return count_greater(root, key);
	}
	size_t count_greater_equal(const Key&key)
	{
		return root->size-count_less(root, key);
	}
	size_t count_greater(Node*r, Key key)//这里不对，size是没错，但是，左旋右旋调整之后相等节点不一定还在左边，也可能走到右边去
	{
		if (r == NIL)
			return 0;
		else if (key >= r->key)
			return count_greater(r->rchild, key);
		else
			return count_greater(r->lchild, key) + r->rchild->size + 1;
	}

	Node*select(int i)
	{
		//assert(i > 0 && i <= root->size);
		if (i > root->size || i < 1)
			return NIL;
		for (Node *p = root; p != NIL;)
		{
			if (p->lchild->size + 1 > i)
			{
				p = p->lchild;
			}
			else if (p->lchild->size + 1 < i)
			{
				i -= p->lchild->size + 1;
				p = p->rchild;

			}
			else
			{
				return p;
			}
		}
	}
	int rank(Key key)//中序遍历的次序
	{
		Node*x = find_(key);
		if (x == NIL)
			return -1;
		int r = x->lchild->size + 1;
		Node*y = x;
		while (y != root)
		{
			if (y == y->p->rchild)
				r += y->p->lchild->size + 1;
			y = y->p;
		}
		return r;
	}
	int get_node_count()
	{
		return root->size;
	}

	bool insert(const Key key,const Value value=0)
	{
		key_count++;
		Node*p = NIL;
		Node*c = root;
		while (c!=NIL)//暂时不考虑key相同的情况
		{
			//assert(key != c->key);//不能插入相同的key

			c->size++;
			if (key <= c->key)//等于放左边 
				//左旋右旋的过程中很有可能把相等的节点分散到左右子树里面
			{
				p = c;
				c = c->lchild;
			}
			else if (key > c->key)
			{
				p = c;
				c = c->rchild;
			}
		}
		Node*z = create_node(key, value);//默认为红节点
		z->p = p;
		z->lchild = NIL;
		z->rchild = NIL;
		
		if (p==NIL)
			root = z;
		else if (key <= p->key)//等于放左边
			p->lchild = z;
		else if (key > p->key)
			p->rchild = z;
		insert_fixup(z);
		return true;
	}
	Value find(Key key)
	{
		return find_(key)->value;
	}
	bool remove(const Key key)
	{
		
		Node*c = root;
		while (c != NIL && key != c->key)//先找到 重复节点先不管
		{
			c->size--;//路径上的每一个点都要相应减少
			if (key < c->key)
				c = c->lchild;
			else if (key > c->key)
				c = c->rchild;
		}
		z = c;
		if (z == NIL)
			return false;
		key_count--;

		Node*y = z;
		Node*x;
		Color y_original_color = y->color;
		if (z->lchild==NIL)
		{
			x = z->rchild;
			transplant(z, z->rchild);
		}
		else if (z->rchild==NIL)
		{
			x = z->rchild;
			transplant(z, z->lchild);
		}
		else
		{
			y = minimun_(z->rchild);
			y_original_color = y->color;
			x = y->rchild;

			if (y->p == z)
				x->p = y;//因为x有可能是NIL 
			else
			{
				transplant(y, y->rchild);
				y->rchild = z->rchild;
				y->rchild->p = y;
			}
			transplant(z, y);
			y->lchild = z->lchild;
			y->lchild->p = y;
			y->color = z->color;
		}
		if (y_original_color == black)
			delete_fixup(x);
		return true;
	}
	void print()//先序遍历的
	{
		print_(root);
		cout << endl;
	}
	int get_key_count()
	{
		return key_count;
	}
private:
	Node*NIL;
	Node*root;
	int key_count;
	Node*find_(const Key key)
	{
		Node*c = root;
		while (c != NIL && key != c->key)
		{
			if (key < c->key)
				c = c->lchild;
			else if (key > c->key)
				c = c->rchild;
		}
		return c;
	}
	void free(Node*r)
	{
		if (r == NIL)
			return;
		else
		{
			free(r->lchild);
			free(r->rchild);
			delete r;
		}
	}
	Node*create_node(Key key, Value value)
	{
		Node*node = new Node(key, value);
		node->color = red;
		node->lchild = node->rchild = node->p = NIL;
		return node;
	}
	void delete_fixup(Node*x)
	{
		while (x != root && x->color == black)
		{
			if (x == x->p->lchild)
			{
				Node*w = x->p->rchild;
				if (w->color == red)//case1 可以转换成case2 3 4 也就是w是黑色
				{
					w->color = black;
					x->p->color = red;//这里已经将x->p设为red 满足循环跳出条件
					left_rotate(x->p);
					w = x->p->rchild;
				}
				if (w->lchild->color == black && w->rchild->color == black)//case2 如果是由case1 转换来的，会直接结束，因为
				{
					w->color = red;
					x = x->p;
					continue;
				}
				else if (w->rchild->color == black)//case3 w右孩是黑色，旋转成红色
				{
					w->lchild->color == black;
					w->color = red;
					right_rotate(w);
					w = x->p->rchild;
				}
				w->color = x->p->color;//w 右孩为红色 搞完就结束
				x->p->color = black;
				w->rchild->color = black;
				left_rotate(x->p);
				x = root;
				//观察 其实只有case2会循环(如果不是由case1转换来的话）
			}
			else
			{
				Node*w = x->p->lchild;
				if (w->color == red)//case1 可以转换成case2 3 4
				{
					w->color = black;
					x->p->color = red;//这里已经将x->p设为red 满足循环跳出条件
					right_rotate(x->p);
					w = x->p->lchild;
				}
				if (w->lchild->color == black && w->rchild->color == black)//case2 如果是由case1 转换来的，会直接结束，因为
				{
					w->color = red;
					x = x->p;
					continue;
				}
				else if (w->lchild->color == black)//case3 w右孩是黑色，旋转成红色
				{
					w->rchild->color == black;
					w->color = red;
					left_rotate(w);
					w = x->p->lchild;
				}
				w->color = x->p->color;//w 
				x->p->color = black;
				w->lchild->color = black;
				right_rotate(x->p);
				x = root;
			}
		}
		x->color = black;

	}
	Node*minimun_(Node*r)
	{
		Node*p = r;
		Node*f = r->p;
		while (p!=NIL)
		{
			f = p;
			p = p->lchild;
		}
		return f;
	}
	void transplant(Node*u, Node*v)
	{
		if (u->p==NIL)
			root = v;
		else if (u == u->p->lchild)
			u->p->lchild = v;
		else
			u->p->rchild = v;
		v->p = u->p;
	}
	void print_(Node*root)
	{
		if (root==NIL)
			return;
		else
		{
			print_(root->lchild);
			cout << root->key << " ";
			print_(root->rchild);
		}
	}
	void insert_fixup(Node*z)
	{
		//while (z&&z->p&&z->p->color == red)
		auto myself = z;
		auto father = z->p;
		auto grandpa = father->p;
		Node*uncle;
		
		while(z->p->color==red)
		{
			if (z->p == z->p->p->lchild)
			{
				Node*y = z->p->p->rchild;
				uncle = y;
				if (y->color == red)//case1
				{
					z->p->color = black;
					y->color = black;
					z->p->p->color = red;
					z = z->p->p;
					continue;
				}
				else if (z == z->p->rchild)//case2
				{
					z = z->p;
					left_rotate(z);
				}
				z->p->color = black;//case3 case2可以转变成case3//相当于把右孩换到左孩
				//if (!z->p->p)
				//	break;
				z->p->p->color = red;//这里不可能出现z->p->p==NIL的情况，因为这样的话，z->p就是根节点了
				right_rotate(z->p->p);
			}
			else
			{
				Node*y = z->p->p->lchild;
				if(y->color==red)
				{
					z->p->color = black;
					y->color = black;
					z->p->p->color = red;
					z = z->p->p;
					continue;
				}
				else if (z == z->p->lchild)//case2
				{
					z = z->p;
					right_rotate(z);
				}
				z->p->color = black;//case3 case2可以转变成case3
				//if (!z->p->p)
				//	break;
				z->p->p->color = red;
				left_rotate(z->p->p);

			}
		}
		root->color = black;
	}
	/*左旋右旋顾名思义的特点：
	1,rotate(x):都是把x往下拉，把孩子往上提。
	2,左旋就是把x往左下拉
	3，右旋就是把x往右下拉
	*/
	void left_rotate(Node*x)
	{
		Node*y = x->rchild;
		x->rchild = y->lchild;
		if (y->lchild!=NIL)
			y->lchild->p = x;//我靠，尼玛，就这里错了然后改了一整天
		y->p = x->p;
		if (x->p==NIL)
			root = y;
		else if (x == x->p->lchild)
			x->p->lchild = y;
		else
			x->p->rchild = y;
		y->lchild = x;
		x->p = y;


		y->size = x->size;
		x->size = 1 + x->lchild->size + x->rchild->size;
	}
	void right_rotate(Node*x)
	{
		Node*c = x->lchild;
		x->lchild = c->rchild;
		if (c->rchild!=NIL)
			c->rchild->p = x;
		c->p = x->p;
		if (x->p==NIL)
			root = c;
		else if (x == x->p->lchild)
			x->p->lchild = c;
		else
			x->p->rchild = c;

		x->p = c;
		c->rchild = x;

		c->size = x->size;
		x->size = 1 + x->lchild->size + x->rchild->size;//简单修改一下即可
	}

};
```
