思路：中间重复过程没有必要一个一个看
注意：在执行用时分布图标看到很多人是差不多的思路 但是用的是list记录路径 搜索的话还是dict和set快一些
本人菜鸡 主要的语句都添加了注释 请大家多多指教
```
class Solution:
	def robot(self,command,obstacles,x,y):
		situ={0:{0}} #记录初始点的位置 key是横坐标 val是纵坐标
		count_x,count_y=0,0
		for i in command: #遍历记录第一次完整循环过程可能经过的坐标点
			if i=="R":
				count_x+=1
			else:
				count_y+=1
			situ.setdefault(count_x,set()).add(count_y) #用的是set() 方便查找
		hori,vert=count_x,count_y #一次完整的循环横向移动的距离 纵向移动的距离
		obstacles=[[x,y]]+[[i,j] for i,j in obstacles if i<=x and j<=y] #把目的点也作为障碍物 同时清理掉一些无效障碍物
		flag=True #True表示当前障碍物是假障碍物
		for x,y in obstacles:
			turns,dis_x=divmod(x,hori)
			dis_y=y-turns*vert
			res=dis_y in situ[dis_x] if situ.get(dis_x,None) is not None else False #因为有可能situ[dis_v]会报错 所以先get
			if flag: #说明这个是目的点
				if res:
					flag=False
					continue
				return False
			elif res: #被障碍物挡着了 所以是False
				return False
		return True #一路上畅通无阻 所以True
```
