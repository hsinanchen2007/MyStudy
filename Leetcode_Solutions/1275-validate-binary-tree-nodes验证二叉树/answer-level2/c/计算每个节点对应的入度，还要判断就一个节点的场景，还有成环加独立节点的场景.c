#define MAX_SIZE 10000

bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize){
    int inCnt[MAX_SIZE] = {0};
    
    // 计算所有节点的入度
    for (int i = 0; i < n; i++) {
        if (leftChild[i] != -1) {
            inCnt[leftChild[i]] += 1;   
            if (inCnt[leftChild[i]] > 1) {
                return false;
            }
        }
        
        if (rightChild[i] != -1) {
            inCnt[rightChild[i]] += 1;    
            if (inCnt[rightChild[i]] > 1) {
                return false;
            }            
        }        
    }

    // 统计入度为0的个数，统计入度大于1的个数
    int zeroCnt = 0;
    int oneCnt = 0;
    int root = 0;
    
    for (int i = 0; i < n; i++) {
        if (inCnt[i] == 0) {
            zeroCnt++;         
            root = i;
        } else if (inCnt[i] == 1) {
            oneCnt++;            
        } else {
            return false;
        }       
    }    
    
    if (zeroCnt == 1) {
        // 判断就一个节点的场景
        if (oneCnt == 0) {
            return true; 
        } else if ((leftChild[root] != -1) || (rightChild[root] != -1) ) {
            // 还要计算root的出度不能为0
            return true;            
        }
    }
    
    return false;
}