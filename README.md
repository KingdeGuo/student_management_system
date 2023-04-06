# student_management_system
C语言实现的学生管理系统 学生成绩管理系统

# C语言学生管理系统

- **用C语言实现一个学生成绩管理系统题目**： 学生成绩管理系统
- **功能**： 实现学生信息管理。包括：录入、查询、排序等功能。
要求： 用数据文件保存学生基本信息(学号 姓名  课程1  课程2 课程3…) ,利用菜单可以循环实现各个功能。
- **进一步要求***： (1) 能够实现增加、删除、修改功能；
(2) 能够实现统计功能等。
- **思路简介：**  要采用模块化思想，对不同的功能编写不同的函数进行实现
- **不足之处：**  没有查重处理，需要进一步完善
比如此结构体中，定义有学号，在函数查找、修改等功能中也是通过学号来查找。
没有查重则对结果影响比较大。举例来说，原本数据存有学号为 20190156 的学生
。当你选择增加数据且再次输入一个学号为 20190518 的学生数据时，程序并不会
报错，只是默默的存在在数据文件中。所以这就带来了很大的隐患。当你继续选择
查找功能时，假如你输入的学号是 20190518 ，这时候计算机就不知道怎么处理了
。在实际生活中情况可能更复杂，带来更大的隐患。所以应该增加查重环节并对数
据进一步处理。

# 欢迎大家关注我的公众号【kingdeguo】
![https://github.com/KingdeGuo/myPictureBed/blob/main/img_upload2023/%E5%85%AC%E4%BC%97%E5%8F%B7%E4%BA%8C%E7%BB%B4%E7%A0%81.jpeg](https://github.com/KingdeGuo/myPictureBed/blob/main/img_upload2023/%E5%85%AC%E4%BC%97%E5%8F%B7%E4%BA%8C%E7%BB%B4%E7%A0%81.jpeg)

# 赞赏作者
![https://github.com/KingdeGuo/myPictureBed/blob/main/img_upload2023/%E6%94%B6%E6%AC%BE%E7%A0%81.jpg](https://github.com/KingdeGuo/myPictureBed/blob/main/img_upload2023/%E6%94%B6%E6%AC%BE%E7%A0%81.jpg)