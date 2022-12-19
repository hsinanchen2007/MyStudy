```

class Heap
{
public:
    int n;
    int tail;
    vector<ListNode*> arr;

    void setN(int in_n)
    {
        n = in_n;
        tail = -1;
        arr.resize(n);
    }

    void insert(ListNode* node)
    {
        if(node == NULL) return;
        tail++;

        int i = tail;
        arr[i] = node;
        
        while(i>=1)
        {
            if(arr[(i-1)/2]->val > arr[i]->val) {
                swap(arr[(i-1)/2], arr[i]);
                i = (i-1)/2;
            } else {
                break;
            }
        }
    }
    
    ListNode* pop()
    {
       ListNode* temp = arr[0];

       swap(arr[0], arr[tail]);
       tail--;
       int i = 0;
       while(true) {
            int minPos = i;
            if(i* 2+ 1 <= tail && arr[i*2+1]->val < arr[i]->val) {
                minPos = i * 2 +1;
            }

            if(i* 2+ 2 <= tail && arr[i*2+2]->val < arr[minPos]->val) {
                minPos = i * 2 +2;
            }
            if(minPos == i) {
                break;
            }
            swap(arr[minPos], arr[i]);
            i = minPos;
       }

       return temp;
    }

    int isEmpty()
    {
        return tail == -1;
    } 

    void print()
    {
        for (int i = 0; i <= tail; ++i)
        {
            cout<<arr[i]->val<<":";
        }
        cout<<endl;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* point = res;

        Heap heap;
        heap.setN(lists.size());
        for (int i = 0; i < lists.size(); ++i)
        {
            heap.insert(lists[i]); 
        }
    
        while(!heap.isEmpty())
        {
            point->next = heap.pop();
            point = point->next;
            if(point->next != NULL)
            {
                heap.insert(point->next);
            }
        }
        return res->next;
    }
};

```
