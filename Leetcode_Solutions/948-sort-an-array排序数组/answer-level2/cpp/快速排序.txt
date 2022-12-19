### 解题思路
标准的快排

### 代码

```cpp
struct SortStruct
{
	vector<int> front;
	vector<int> back;
	int splitIndex;

};

SortStruct split(vector<int> nums);
vector<int> quickSort(vector<int> nums);

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return quickSort(nums);
    }
};

SortStruct split(vector<int> nums){
	int splitIndex = 0;
	int split = nums[0];
	vector<int> front;
	vector<int> back;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < split){
			front.push_back(nums[i]);
			splitIndex++;
		}
		else{
			back.push_back(nums[i]);
		}
	}
	SortStruct result;
	result.front = front;
	result.back = back;
	result.splitIndex = splitIndex;

	/*cout << "****** front *******" << endl;
	for (int i = 0; i < result.front.size(); i++)
	{
		cout << result.front[i];
	}
	cout << "*******************" << endl;
	
	cout << "****** back *******" << endl;
	for (int i = 0; i < result.back.size(); i++)
	{
		cout << result.back[i];
	}
	cout << "*******************" << endl;*/

	return result;
}

vector<int>quickSort(vector<int> nums){
	if (nums.size() < 2){
		return nums;
	}

	vector<int> result;
	int splitIndex = -1;

	
	SortStruct process = split(nums);

	//cout << "****** front *******" << endl;
	//for (int i = 0; i <process.front.size(); i++)
	//{
	//	cout << process.front[i];
	//}
	//cout << endl << "*******************" << endl;

	//cout << "****** back *******" << endl;
	//for (int i = 0; i <process.back.size(); i++)
	//{
	//	cout << process.back[i];
	//}
	//cout << endl << "*******************" << endl;

	

	int splitNum = nums[0];

	//cout << "split " << splitNum << endl;

	vector<int> front = quickSort(process.front);
	vector<int> back = quickSort(process.back);


	

	if (front.size() != 0){
		result.insert(result.end(), front.begin(), front.end());
	}
	result.push_back(splitNum);
	if (back.size() != 0){
		result.insert(result.end(), back.begin(), back.end());
	}
	
	return result;


}
```