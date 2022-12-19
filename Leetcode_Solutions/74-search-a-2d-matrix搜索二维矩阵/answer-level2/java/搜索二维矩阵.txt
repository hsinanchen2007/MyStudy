//二分搜索，先从最左边开始竖向搜索，找到mid，然后在横向搜索
```
public boolean searchMatrix(int[][] matrix, int target) {
    	if(matrix.length == 0 || matrix[0].length == 0 || 
    			matrix[0][0] > target || matrix[matrix.length - 1][matrix[0].length - 1] < target)
    	   return false;
    	//按列搜索
        int leftV = 0,rightV = matrix.length;
        int mid = 0;
        int temp = 0;
        while(leftV <= rightV) { 
        	mid = (leftV + rightV)/2;
        	temp = matrix[mid][matrix[0].length - 1];
        	if(temp == target)
        		return true;
        	if(temp < target) 
        		leftV = mid + 1;
        	if(temp > target)
        		rightV = mid - 1;
        }
        //按行搜索
        if(temp < target) mid++;
        int leftC = 0, rightC = matrix[0].length - 1;
        while(leftC <= rightC) {
        	int nMid = (leftC + rightC) / 2;
        	int x = matrix[mid][nMid];
        	if(x == target)
        		return true;
        	if(x < target)
        		leftC = nMid + 1;
        	if(x > target)
        		rightC = nMid - 1;
        }
        return false;
    }
```
