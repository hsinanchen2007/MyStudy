![QQ图片20190818001418.png](https://pic.leetcode-cn.com/765896238bdb363fb7b048c5806deebc2b1e390224350a80f1a473423bd9c305-QQ%E5%9B%BE%E7%89%8720190818001418.png)
举个栗子： a/b = 2 b/c = 3 
![示意图.png](https://pic.leetcode-cn.com/2daaabb0b2b88f515fe37e80bbffc29fabe5465666d08ada140fc4b8475448b3-%E7%A4%BA%E6%84%8F%E5%9B%BE.png)
如上图，构造一个双向的图 从分子指向分母的就是给的值，从分母指向分子的就是倒数。
定义一个结构体，记录邻居节点的
```
	struct node
	{
		double v;//比值
		string tar;	//指向的节点
	};
	
	map<string,vector<node> >mp;//键是某个节点的名字，值是该节点的所有邻接节点构成的容器
	map<string,int> visited;//记录某个节点是否被访问过
```
整体思路就是对于每个给定的比值，转化为两个节点是否联通的问题。连同就返回路径，然后根据路径算出来比值。

主要算法就是 DFS

```
 bool DFS(string start,string end,vector<string>&road,bool flag)
    {
    	visited[start]=1;//开始节点记录为访问过
    	road.push_back(start);//开始节点存入容器
    	if(mp.count(start)==0)//如果map中没有这个节点直接返回false
    	{
    		return false;
		}
    	if(start==end)//自己到自己，只需将自己放入容器
    	{
    		return true;	
		}
    	for(int i=0;i<mp[start].size();i++)
    	{
    		
    		if(mp[start][i].tar==end)
    		{
    			road.push_back(end);
    			flag = true;
    			return true;
			}
			if(visited[mp[start][i].tar]==1)
			continue;
			 flag = DFS(mp[start][i].tar,end,road,flag);
			if(!flag)//没有走通就pop
			{
				road.pop_back();
			}
			else
			{
				break;
			}
		}
    	return flag;
	}
```
全部代码，还有测试数据，估计有很多冗余，大神轻喷：
```
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
class Solution {
public:
	struct node
	{
		double v;
		string tar;	
	};
	
	map<string,vector<node> >mp;
	map<string,int> visited;
    vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
    	vector<double> result;
        for(int i=0;i<equations.size();i++)
        {
        	visited[equations[i][0]] = 0;
        	visited[equations[i][1]] = 0;
        	node n1,n2;
        	n1.v = values[i];
        	n1.tar = equations[i][1];
        	mp[equations[i][0]].push_back(n1);
        	n2.v = 1.0/values[i];
        	n2.tar = equations[i][0];
        	mp[equations[i][1]].push_back(n2);
		}
		double carry = 1;
		bool flag = false;
	
		for(int i=0;i<queries.size();i++)
		{		
			vector<string>road;
			bool res = DFS(queries[i][0],queries[i][1],road,flag);
			clear();
		if(!res)
		{
			road.clear();
		}
		double value = GetV(road);
	
		result.push_back(value);
		}
		
		return result;
    }
    double GetV(vector<string>road)
    {
    	double c = 1.0;
    	if(road.empty())
    	{
    		return -1.0;
		}
    	else if(road.size()==1)
    	{
    		return 1.0;
		}
		else
		{
			for(int i=0;i<road.size()-1;i++)
			{
				int index = 0;
				while(mp[road[i]][index].tar!=road[i+1])
				{
					
					index++;
				}

				c*=  mp[road[i]][index].v;
			}
		}
	return c;
	
	}
	void clear()
	{
		map<string,int>:: iterator it;
		for(it=visited.begin();it!=visited.end();it++)
		{
			it->second = 0;
		}
	}
    bool DFS(string start,string end,vector<string>&road,bool flag)
    {
    	visited[start]=1;
    	road.push_back(start);
    	if(mp.count(start)==0)
    	{
    		return false;
		}
    	if(start==end)
    	{
    		return true;	
		}
    	for(int i=0;i<mp[start].size();i++)
    	{
    		
    		if(mp[start][i].tar==end)
    		{
    			road.push_back(end);
    			flag = true;
    			return true;
			}
			if(visited[mp[start][i].tar]==1)
			continue;
			 flag = DFS(mp[start][i].tar,end,road,flag);
			if(!flag)
			{
				road.pop_back();
			}
			else
			{
				break;
			}
		}
    	return flag;
	}
};
int main()
{
	vector<vector<string> > equations;
	vector<double> values;
	vector<vector<string> > queries;
	vector<string>e1;
	e1.push_back("a");
	e1.push_back("e");
	vector<string>e2;
	e2.push_back("b");
	e2.push_back("e");
	vector<string>e3;
	e3.push_back("f");
	e3.push_back("g");
	equations.push_back(e1);
	equations.push_back(e2);
//	equations.push_back(e3);
	values.push_back(4.0);
	values.push_back(3.0);
//	values.push_back(5.0);
	vector<string>q1;
	vector<string>q2;
	vector<string>q3;
	vector<string>q4;
	vector<string>q5;
	q1.push_back("a"); 
	q1.push_back("b");
	q2.push_back("e");
	q2.push_back("e");
	q3.push_back("x");
	q3.push_back("x");
	q4.push_back("g"); 
	q4.push_back("f");
	q5.push_back("a");
	q5.push_back("x");
	vector<vector<string>>Q;
	Q.push_back(q1);
	Q.push_back(q2);
	Q.push_back(q3);
//	Q.push_back(q4);
//	Q.push_back(q5);
	Solution s;
	vector<double>res =  s.calcEquation(equations,values,Q);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
```


