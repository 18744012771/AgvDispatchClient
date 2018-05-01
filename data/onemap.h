﻿#ifndef ONEMAP_H
#define ONEMAP_H

#include "mapfloor.h"
#include "mapbackground.h"
#include <QImage>
//一个地图[有若干个元素组成]
class OneMap
{
public:
    OneMap();
    ~OneMap();
    //注册一个新的元素
    int getNextId();

    void addSpirit(MapSpirit *spirit);

    void setBackgroudImage(QImage img,QString name){
        QList<MapSpirit *> backgrounds = getSpiritByType(MapSpirit::Map_Sprite_Type_Background);
        foreach (auto s, backgrounds) {
            removeSpirit(s);
        }
        MapBackground *bs = new MapBackground(getNextId(),name,-1*img.width()/2,-1*img.height()/2,img.width(),img.height());

        addSpirit(bs);
    }

    //删除一个元素
    void removeSpirit(int id);
    void removeSpirit(MapSpirit *spirit);

    //复制地图（深copy）
    OneMap clone();

    QList<MapSpirit *> getSpirits(){return spirits;}

    MapSpirit *getSpiritById(int id);

    QList<MapSpirit *> getSpiritByType(MapSpirit::Map_Spirit_Type type);
private:
    QList<MapSpirit *> spirits;//地图上的所有元素
    int max_id;
};

#endif // ONEMAP_H
