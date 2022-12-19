首先我们必须明白一辆车的行驶只受前方车辆的影响（后面车辆追上他之后不会影响他自己的速度，他仍然应该被当成一个独立的点）。
其次原问题应该被抽象为一条线上各点的运动问题，我们最终的目标是根据位置顺序划分点集合(like:positon=={1,3,5,7，9}，
positon_seperated={1,3|5,7|9});
我们自然想到每一次按照位置降序考虑每一个点，该点前方的点在终点之前或者终点相遇就属于一个车队，否则计数器+1（即该点独立于前一个车队）。
我们可以实时记录每一点的实际到达时间，然后在计算每个点按照自己速度匀速前往终点的时间t0和前方的点到达时间t1进行比较：
（1）if t0<=t1，显然肯定相遇。
 现在我们的问题是如果相遇，那么t0<=t1是否一定成立（充分必要条件中这一端是不够显然的）--->
（2）我们假设两个点相遇了，由于后面的点刚开始的位置在后方，那么如果他初始速度一定快于前方的点，那么如果他们相遇在终点，那么t0=t1,如果他们相遇在中间，显然如果原来在后方的点继续按照自己的速度行驶，他会先到达终点。
至此我们证明了一个点和前方点属于同车队的条件，那么用循环来计数就很简单了。
代码运行效率似乎不怎么样，算法还是比较清晰的，勿喷（懒得扣效率了，思路清晰自己看得爽就行了）。
int com(vector<int> &a1,vector<int> &a2)
    {
        return a1[0]>a2[0];
    }   //比较函数，用来排序；
class Solution {
public:
   
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<vector<int>> infor;
	    int ans=1;
        for (int i = 0; i < position.size(); i++)
		infor.push_back({ position[i],speed[i] });   //先处理位置和速度信息进数组；
	    sort(infor.begin(), infor.end(), com);
	    if(infor.empty())
            return 0;
	double reach = double(target - infor[0][0]) / infor[0][1];  //首先记录最前面的点的到达时间（相当于数学归纳法的第一步，很重要）
	double temp;
	for (int i = 0; i < infor.size(); i++)
	{
	  temp= double(target - infor[i][0]) / infor[i][1];
	  if (temp > reach)
		  ans++, reach = temp;   //注意如果不属于一个车队需要更新到达时间（下面一个点需要的是上面一个点的实际到达时间不是全速到达时间）
	 
	}
	return ans;
    }
};