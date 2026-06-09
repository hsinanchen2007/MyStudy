**1. 先按seller_id和order_date排序**
```
SELECT *
FROM Orders
GROUP BY seller_id, order_date
```
**2. 找出每个seller_id的第二个item**
添加两个变量：rank记录每个item的顺序；pre_seller_id记录前一个seller_id。
如果当前seller_id和pre_seller_id一样，rank加1；如果不一样，rank重新开始计数。
```
SELECT item_id, seller_id, 
       @rank := CASE WHEN @pre_seller_id = seller_id THEN @rank + 1
                     ELSE 1
                END AS rank,
       @pre_seller_id := seller_id AS pre_seller_id
FROM 
    (SELECT *
     FROM Orders
     GROUP BY seller_id, order_date) o,
    (SELECT @pre_seller_id := NULL, @rank := 0) init
```
rank = 2的行就是第二个item。

**3. 将2.得到的表命名为need，和表Items和表Users连接起来**
首先和Items连接起来，这里用INNER JOIN就够了，再和Users连接起来，这里要用外连接，注意：RIGHT JOIN加上WHERE之后等同于INNER JOIN，因为是先RIGHT JOIN，再WHERE，null的行被筛掉了，所以要将WHERE rank = 2换成ON中的AND rank = 2。
```
SELECT *
FROM 
    (SELECT item_id, seller_id, 
            @rank := CASE WHEN @pre_seller_id = seller_id THEN @rank + 1
                          ELSE 1
                     END AS rank,
            @pre_seller_id := seller_id AS pre_seller_id
     FROM 
         (SELECT *
          FROM Orders
          GROUP BY seller_id, order_date) o,
         (SELECT @pre_seller_id := NULL, @rank := 0) init) need 
INNER JOIN Items ON need.item_id = Items.item_id
RIGHT JOIN Users ON Users.user_id =  need.seller_id AND need.rank = 2
```
**4. 选出所有seller_id和对应的2nd_item_fav_brand**
```
SELECT Users.user_id seller_id, 
       CASE WHEN Items.item_brand IS NULL OR Items.item_brand != Users.favorite_brand 
            THEN 'no'
            ELSE 'yes'
        END 2nd_item_fav_brand
FROM 
    (SELECT item_id, seller_id, 
            @rank := CASE WHEN @pre_seller_id = seller_id THEN @rank + 1
                          ELSE 1
                     END AS rank,
            @pre_seller_id := seller_id AS pre_seller_id
     FROM 
         (SELECT *
          FROM Orders
          GROUP BY seller_id, order_date) o,
         (SELECT @pre_seller_id := NULL, @rank := 0) init) need 
INNER JOIN Items ON need.item_id = Items.item_id
RIGHT JOIN Users ON Users.user_id =  need.seller_id AND need.rank = 2
```

