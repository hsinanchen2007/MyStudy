初步思路是使用扫秒链表，如果遇到节点在G中的，开始统计组件个数；节点不在G中的，退出统计。
整体就是个状态机模式，直接线性扫描即可，内存消耗极小。
判断节点是否在子集合里面的操纵，可以优化为哈希表，性能会更高。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static bool isValInG(int val, int* G, int GSize)
{
    int i;

    for (i = 0; i < GSize; ++i) {
        if (val == G[i]) {
            return true;
        }
    }

    return false;
}

enum ComponentScanState {
    COMPONENT_SCAN_IN = 0,
    COMPONENT_SCAN_OUT = 1,
};

int numComponents(struct ListNode* head, int* G, int GSize) {
    enum ComponentScanState state = COMPONENT_SCAN_OUT;
    struct ListNode* pos = NULL;
    int componentNumber = 0;

    if (head == NULL) {
        return 0;
    }

    if (G == NULL) {
        return 0;
    }

    if (GSize <= 0) {
        return 0;
    }

    for (pos = head; pos != NULL; pos = pos->next) {
        const bool isInG = isValInG(pos->val, G, GSize);

        // 通过状态机来记录组件个数。
        // 当前一个组件扫描结束后，又遇到了合法字符，就进行记录，并切换状态为COMPONENT_SCAN_OUT
        if (state == COMPONENT_SCAN_OUT) {
            if (isInG) {
                state = COMPONENT_SCAN_IN;
                componentNumber++;
            }
        } else {
            // 进入in状态后，下个元素继续在G中，不退出in状态。
            // 如果是最后一个元素，不需要做特殊处理。在in状态中不会多统计，在out状态中也不会多统计
            if (isInG) {
                // do nothing
            } else {
                state = COMPONENT_SCAN_OUT;
            }
        }
    }

    return componentNumber;
}
