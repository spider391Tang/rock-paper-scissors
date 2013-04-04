//
//  main.cpp
//  rock-paper-scissors
//
//  Created by HSIN LEI TANG on 13/4/1.
//  Copyright (c) 2013年 HSIN LEI TANG. All rights reserved.
//
//  http://blog.csdn.net/bkxxf/article/details/7592525
//
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Rock;
class Paper;
class Scissors;


class Visitor
{
public:
    
    virtual void compare( const Rock& r ) const = 0;
    virtual void compare( const Paper& p ) const = 0;
    virtual void compare( const Scissors& s ) const = 0;
};



class Element
{
public:
    virtual void accept( const Visitor& v ) = 0;
};

class Rock : public Element
{
public:
    virtual void accept( const Visitor& v )
    {
        v.compare( *this );
    }
};

class Paper : public Element
{
public:
    virtual void accept( const Visitor& v )
    {
        v.compare( *this );
    }
};

class Scissors: public Element
{
public:
    virtual void accept( const Visitor& v )
    {
        v.compare( *this );
    }
};


class RockVisitor : public Visitor
{
public:
    virtual void compare( const Rock& r ) const
    {
        cout << "The Same.\n";
    }
    virtual void compare( const Paper& p ) const
    {
        cout << "You Lose!\n";
    }
    virtual void compare( const Scissors& s ) const
    {
        cout << "You Win!!\n";
    }
};


class PaperVisitor : public Visitor
{
public:
    virtual void compare( const Rock& r ) const
    {
        cout << "You Win!!.\n";
    }
    virtual void compare( const Paper& p ) const
    {
        cout << "Same!\n";
    }
    virtual void compare( const Scissors& s ) const
    {
        cout << "You Lose!!\n";
    }
};

class ScissorsVisitor : public Visitor
{
public:
    virtual void compare( const Rock& r ) const
    {
        cout << "You Lose!\n";
    }
    virtual void compare( const Paper& p ) const
    {
        cout << "You Win!\n";
    }
    virtual void compare( const Scissors& s ) const
    {
        cout << "Same!!\n";
    }
    
};


int main() {
    vector<shared_ptr<Element> > e;
    e.push_back( shared_ptr<Element>( new Paper() ) );
    e.push_back( shared_ptr<Element>( new Rock() ) );
    e.push_back( shared_ptr<Element>( new Scissors() ) );
    
    shared_ptr<Visitor> v( new RockVisitor() );
    for( vector<shared_ptr<Element> >::iterator it = e.begin();
        it != e.end(); ++it )
    {
        (*it)->accept( *v );
    }
    
    return 0;
}
