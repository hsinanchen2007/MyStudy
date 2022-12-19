 #### “下一个排序”是什么？
 
 我们可以写出一个数字更多的例子来观察
 
 `1234`
 
 `1243`
 
 `1324`
 
 `1342`
 
 `1423`
 
 `1432`
 
 `2134`
 
 `2143`
 
 `2314`
 
 `2342`
 
 `...`
 
 建议读者自己也写一遍，以便于更好的理解我下面的话
 
 我们在写的时候是如何得到下一个的？为了得到比当前排列大的排列中最小的那个，我们需要保证大小在增加，但增加的幅度是最小的。
 所以我们会让小的数字尽可能的处在高位，大的数字处在低位。因为起始情况是小的最优解，我们每次变换应该尽可能的只动较低的位。
 
 具体的来看，从`1234`开始，我们只动最后两位数，让他们交换。到了`1243`,必须要动百位了，我们才从后两位中找出大于旧的百位的数，然后再从中选出最小的做新的百位
 (显然我们不可能选一个比旧的百位小的数去做新百位，虽然暂时在这里还没有这样的数)。
 一直到`1432`,我们便不得不动千位了，于是我们从后三位中选出大于旧千位的，但是是最小的一个做新的千位。
 
 如果读者还是很难理解，我们以`2431`做例子。我们需要改变千位，但我们不可能选1，那样反而会变小。所以我们选3,4中较小的3做新的千位。
 
 什么时候我们需要动更高位？通过观察我们不难发现，只有低位已经是从高到低是从大到小排列的(例如`1243`中的`43`,`1432`中的`432`)，也就是低位全部满足了`nums[n+1]>nums[n]`，
 我们把这样的情况命名为k位下有序(如`1243`就是百位下有序，`1432`就是千位下有序)，
 此时较低位已经到了他们的最大值，我们必须要改变更高位才能得到更大的数，这是我们解决这道题最重要的概念。
 
 当排列来到最大(如`4321`)，依题意我们需要重新排列成最小的排列。
 
#### 如何得到下一个排序

k位下有序有什么用呢？它可以帮我们找到我们需要改变的最高位。

对于任何一个排列，都必然满足十位下有序，因为后面只有一个个位，一个数自然有序。

对于有的排列可以满足更高位下的有序，我们首先要做的就是找到满足k位下有序的最高位。

此时我们可以发现，得到下一个排列应该分两步：改变需要改变的所有位中的最高位，然后对后面排序即可。

这时我们已经可以把如何得到下一个排序的具体步骤写出来了：

1. 找到最大的k位下有序
2. 改变k位：从后面的数中找出大于原k位上的数的数，然后在这些数中选出最小的一个替换
3. 将k位后面的数字重新排序

#### 得到代码

检测是否i+1位后是否有序 

	bool posi(vector<int> nums,int i){      //无序返回false
        while(i<nums.size()-1){
            if(nums[i]<nums[i+1]){
                return false;
            }
            i++;
        }
        return true;
    }
	
改变k位 

    void getNext(vector<int> & nums,int j){
        if(j==nums.size()-1) return;
        int min=INT_MAX,i=j+1,minP=-1;
        while(i<nums.size()){
            if(nums[i]<min&&nums[i]>nums[j]){	//从大于它的数中选最小的一个
                min=nums[i];
                minP=i;
                show(nums);
            }
            i++;
        }
        if(minP!=-1) swap(nums[j],nums[minP]);
        sort(nums,j+1);
    }
	
k位后排序

    void sort(vector<int>& nums,int j){
    	int end=nums.size()
    	bool sorted=false;
    	while(!sorted){
    		sorted=true;
    		for(int i=j+1;i<end;i++){
    			if(nums[i-1]>nums[i]){
    				swap(nums[i-1],nums[i]);
    				sort=false;
				}
			}
			end--;
		}
    }
	
如果排列是最大时，我们需要改变为最小

    void getMin(vector<int>& nums){
        int i=0,j=nums.size()-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
	
主函数

    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1){
            return; 
        }
        if(nums.size()==2){
            swap(nums[0],nums[1]);
            return;
        }
        int k=0;
        if(posi(nums,k)){
            getMin(nums);
            return;
        }
        while(k<=nums.size()-3){    //找到第一个有序
            if(posi(nums,k+1)){        //k不参与比较
                break;
            }
            k++;
        }
        getNext(nums,k);
    }