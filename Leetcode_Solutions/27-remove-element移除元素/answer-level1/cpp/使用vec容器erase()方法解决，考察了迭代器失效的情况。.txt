
# 数组式容器(vector,deque)
int removeElement(vector<int>& nums, int val) {
    std::vector<int>::iterator iter;
    for (iter = nums.begin(); iter!= nums.end(); )
    {
        if (*iter == val) {
            nums.erase(iter);//erase方法删除iterator指向的元素后，返回的是下一个元素的迭代器，这是vcetor容器自身经过内存调整后的新的有效迭代器。
            continue;
        }
        iter++;
    }
    return nums.size();
}


# 关联式容器(map, set,multimap,multiset)
int removeElement(map<int,string> nums, int val) {
    std::map<int, string>::iterator iter;
    for (iter = nums.begin(); iter != nums.end(); iter++)
    {
        int iKey = iter->first;
        string strVal = iter->second;

        if (iKey % 2 == 0)
        {
            std::map<int, string>::iterator tempIter = iter; //用一个临时变量保存指向当前元素的迭代器
            nums.erase(tempIter); //执行erase删除这个元素
            iter++; //iter自增

            //nums.erase(iter++); //可以吧以上三行写成一行，利用后置++的特性。这句话分三步走，先把iter传值到erase里面，然后iter自增，然后执行erase,所以iter在失效前已经自增了。
        }else
        {
            iter++;
        }
    }
}


# 链表型数据结构(list)，也可以像关联式容器这样使用。




# 总结：迭代器失效分三种情况考虑，也是非三种数据结构考虑，分别为数组型，链表型，树型数据结构。

数组型数据结构：该数据结构的元素是分配在连续的内存中，insert和erase操作，都会使得删除点和插入点之后的元素挪位置，所以，插入点和删除掉之后的迭代器全部失效，也就是说insert(*iter)(或erase(*iter))，然后在iter++，是没有意义的。解决方法：erase(*iter)的返回值是下一个有效迭代器的值。 iter =cont.erase(iter);

链表型数据结构：对于list型的数据结构，使用了不连续分配的内存，删除运算使指向删除位置的迭代器失效，但是不会失效其他迭代器.解决办法两种，erase(*iter)会返回下一个有效迭代器的值，或者erase(iter++).

树形数据结构： 使用红黑树来存储数据，插入不会使得任何迭代器失效；删除运算使指向删除位置的迭代器失效，但是不会失效其他迭代器.erase迭代器只是被删元素的迭代器失效，但是返回值为void，所以要采用erase(iter++)的方式删除迭代器。

注意：经过erase(iter)之后的迭代器完全失效，该迭代器iter不能参与任何运算，包括iter++,*iter