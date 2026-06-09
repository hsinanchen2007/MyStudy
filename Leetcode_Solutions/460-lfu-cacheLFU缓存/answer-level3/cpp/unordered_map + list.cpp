
class LFUCache
{
    typedef int KeyType;
    typedef int ValueType;

    struct Node
    {
        size_t freq;
        KeyType key;
        ValueType value;
    };

    typedef list<Node> CollectionList;



    unordered_map<int, CollectionList::iterator> _m; //快速查找元素
    unordered_map<int, CollectionList> _freqToList;  //要找到频率所对应的链表
    size_t _currentMinFreq;
    size_t _cap;

public:
    static const size_t MinDefaultFreq = 1;

public:
    LFUCache( size_t capacity ) : _m( capacity * 2 + 1 ), _freqToList( capacity * 2 + 1 ), _cap( capacity ), _currentMinFreq( MinDefaultFreq )
    {

    }

    int get( KeyType key )
    {
        auto it = _m.find( key );
        if ( it == _m.end() )
            return -1;

        int oldFreq = it->second->freq;

        auto itListFrom = _freqToList.find( oldFreq );
        auto ListTo = &_freqToList[++it->second->freq];
        ListTo->splice( ListTo->begin(), itListFrom->second, it->second );

        if ( itListFrom->second.size() == 0 )
        {
            _freqToList.erase( itListFrom );
            if ( _currentMinFreq == oldFreq )
            {
                ++_currentMinFreq;
            }
        }

        return it->second->value;
    }

    void put( KeyType key, ValueType value )
    {
        if ( _cap == 0 )
            return;

        auto it = _m.find( key );
        if ( it != _m.end() )
        {
            int oldFreq = it->second->freq;
            auto itListFrom = _freqToList.find( oldFreq );
            auto ListTo = &_freqToList[++it->second->freq];
            ListTo->splice( ListTo->begin(), itListFrom->second, it->second );

            if ( itListFrom->second.size() == 0 )
            {
                _freqToList.erase( itListFrom );
                if ( _currentMinFreq == oldFreq )
                {
                    ++_currentMinFreq;
                }
            }

            it->second = ListTo->begin();
            it->second->value = value;
            return;
        }

        if ( _m.size() >= _cap )
        {
            auto itList = _freqToList.find( _currentMinFreq );
            auto key = itList->second.back().key;
            _m.erase( key );
            itList->second.pop_back();

            if ( itList->second.size() == 0 )
            {
                _freqToList.erase( itList );
            }
        }
        CollectionList::value_type node;

        node.key = key;
        node.value = value;
        node.freq = MinDefaultFreq;
        _currentMinFreq = MinDefaultFreq;
        auto minFreqList = &_freqToList[MinDefaultFreq];

        //minFreqList->push_back( node );
        //_m[key] = --minFreqList->end();

        minFreqList->push_front( node );
        _m[key] = minFreqList->begin();

    }
};
//
//LFUCache* cache = NULL;
//
//
////const char* strings[] = { "LFUCache", "put", "put", "put", "put", "put", "get", "put", "get", "get", "put", "get", "put", "put", "put", "get", "put", "get", "get", "get", "get", "put", "put", "get", "get", "get", "put", "put", "get", "put", "get", "put", "get", "get", "get", "put", "put", "put", "get", "put", "get", "get", "put", "put", "get", "put", "put", "put", "put", "get", "put", "put", "get", "put", "put", "get", "put", "put", "put", "put", "put", "get", "put", "put", "get", "put", "get", "get", "get", "put", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "get", "get", "get", "put", "put", "put", "get", "put", "put", "put", "get", "put", "put", "put", "get", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "put", "put", "put" };
////int arr[][2] = { {10}, {10, 13}, {3, 17}, {6, 11}, {10, 5}, {9, 10}, {13}, {2, 19}, {2}, {3}, {5, 25}, {8}, {9, 22}, {5, 5}, {1, 30}, {11}, {9, 12}, {7}, {5}, {8}, {9}, {4, 30}, {9, 3}, {9}, {10}, {10}, {6, 14}, {3, 1}, {3}, {10, 11}, {8}, {2, 14}, {1}, {5}, {4}, {11, 4}, {12, 24}, {5, 18}, {13}, {7, 23}, {8}, {12}, {3, 27}, {2, 12}, {5}, {2, 9}, {13, 4}, {8, 18}, {1, 7}, {6}, {9, 29}, {8, 21}, {5}, {6, 30}, {1, 12}, {10}, {4, 15}, {7, 22}, {11, 26}, {8, 17}, {9, 29}, {5}, {3, 4}, {11, 30}, {12}, {4, 29}, {3}, {9}, {6}, {3, 4}, {1}, {10}, {3, 29}, {10, 28}, {1, 20}, {11, 13}, {3}, {3, 12}, {3, 8}, {10, 9}, {3, 26}, {8}, {7}, {5}, {13, 17}, {2, 27}, {11, 15}, {12}, {9, 19}, {2, 15}, {3, 16}, {1}, {12, 17}, {9, 1}, {6, 19}, {4}, {5}, {5}, {8, 1}, {11, 7}, {5, 2}, {9, 28}, {1}, {2, 2}, {7, 4}, {4, 22}, {7, 24}, {9, 26}, {13, 28}, {11, 26} };
//
//const char* strings[] = { "LFUCache", "put", "put", "put", "put", "put", "get", "put", "get", "get", "put", "get", "put", "put", "put", "get", "put", "get", "get", "get", "get", "put", "put", "get", "get", "get", "put", "put", "get", "put", "get", "put", "get", "get", "get", "put", "put", "put", "get", "put", "get", "get", "put", "put", "get", "put", "put", "put", "put", "get", "put", "put", "get", "put", "put", "get", "put", "put", "put", "put", "put", "get", "put", "put", "get", "put", "get", "get", "get", "put", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "get", "get", "get", "put", "put", "put", "get", "put", "put", "put", "get", "put", "put", "put", "get", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "put", "put", "put" };
//int arr[][2] = { {10}, {10, 13}, {3, 17}, {6, 11}, {10, 5}, {9, 10}, {13}, {2, 19}, {2}, {3}, {5, 25}, {8}, {9, 22}, {5, 5}, {1, 30}, {11}, {9, 12}, {7}, {5}, {8}, {9}, {4, 30}, {9, 3}, {9}, {10}, {10}, {6, 14}, {3, 1}, {3}, {10, 11}, {8}, {2, 14}, {1}, {5}, {4}, {11, 4}, {12, 24}, {5, 18}, {13}, {7, 23}, {8}, {12}, {3, 27}, {2, 12}, {5}, {2, 9}, {13, 4}, {8, 18}, {1, 7}, {6}, {9, 29}, {8, 21}, {5}, {6, 30}, {1, 12}, {10}, {4, 15}, {7, 22}, {11, 26}, {8, 17}, {9, 29}, {5}, {3, 4}, {11, 30}, {12}, {4, 29}, {3}, {9}, {6}, {3, 4}, {1}, {10}, {3, 29}, {10, 28}, {1, 20}, {11, 13}, {3}, {3, 12}, {3, 8}, {10, 9}, {3, 26}, {8}, {7}, {5}, {13, 17}, {2, 27}, {11, 15}, {12}, {9, 19}, {2, 15}, {3, 16}, {1}, {12, 17}, {9, 1}, {6, 19}, {4}, {5}, {5}, {8, 1}, {11, 7}, {5, 2}, {9, 28}, {1}, {2, 2}, {7, 4}, {4, 22}, {7, 24}, {9, 26}, {13, 28}, {11, 26} };
//
//for ( int i = 0; i != _countof( strings ); ++i )
//{
//    if ( strcmp( strings[i], "LFUCache" ) == 0 )
//    {
//        cache = new LFUCache( arr[i][0] );
//    }
//    else if ( strcmp( strings[i], "put" ) == 0 )
//    {
//        cache->put( arr[i][0], arr[i][1] );
//
//    }
//    else
//    {
//        cache->get( arr[i][0] );
//    }
//}