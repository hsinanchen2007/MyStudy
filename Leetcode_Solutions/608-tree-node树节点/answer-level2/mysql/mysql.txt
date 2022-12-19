主表id左连接附表p_id，即看每个id是否为其他id的父节点，如果附表id为NULL，则该节点不为任意节点的父节点，
主表的p_id可判断该节点是否为其他节点子节点。
```
SELECT DISTINCT t1.id, (CASE WHEN t1.p_id IS NULL
                            THEN 'Root'
						ELSE 
                            CASE WHEN t2.id IS NULL 
                                THEN 'Leaf'
                            ELSE 'Inner' 
                                END 
                        END) as Type
FROM tree t1 left join tree t2 ON t1.id=t2.p_id
```
