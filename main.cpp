//
//  main.cpp
//  laba_7
//
//  Created by Alexandr on 28.05.16.
//  Copyright © 2016 Kamenskiy-Dev. All rights reserved.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <map>




using namespace std;
using namespace this_thread;

bool ready = false;
mutex mtx;
condition_variable cv;

void f1()
{
    for(int i=0; i<21; i++)
    {
        cout<<"aaaaa"<<endl;
        sleep_for(chrono::milliseconds(100));
    }
}

void f2()
{
    for(int i=0; i<21; i++)
    {
        cout<<"bbbbb"<<endl;
        sleep_for(chrono::milliseconds(100));
    }
}

void f3(mutex & m)
{
    int i=0;
    while(i<=25)
    {
        m.lock();
        for(int j=0; j<4; j++)
        {
            cout<<"a";
            sleep_for(chrono::milliseconds(100));
        }
        m.unlock();
        i++;
        sleep_for(chrono::milliseconds(1));
    }
}


void f4(mutex & m)
{
    int i=0;
    while(i<=25)
    {
        m.lock();
        for(int j=0; j<4; j++)
        {
            cout<<"b";
            sleep_for(chrono::milliseconds(100));
        }
        m.unlock();
        i++;
        sleep_for(chrono::milliseconds(1));
    }
}


void f5() {
    unique_lock<mutex> lk(mtx);
    
    for (int i = 0; i < 50; i++) {
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << "b";
    }
    ready = true;
    lk.unlock();
    cv.notify_one();
    
    for (int i = 0; i < 50; i++) {
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << "b";
    }
}


void f6() {
    unique_lock<mutex> lk(mtx);
    cv.wait(lk, [](){ return ready;});
    
    for (int i = 0; i < 50; i++) {
        this_thread::sleep_for(chrono::milliseconds(10));
        cout << "a";
    }
}

void f7(mutex & m)
{
    int i=0;
    while(i<=25)
    {
        m.lock();
        for(int j=0; j<4; j++)
        {
            cout<<"a"<<endl;
            //sleep_for(chrono::milliseconds(10));
        }
        //m.unlock();
        i++;
        //sleep_for(chrono::milliseconds(1));
    }
}

void f8(mutex & m)
{
    int i=0;
    while(i<=25)
    {
        m.lock();
        for(int j=0; j<4; j++)
        {
            cout<<"b"<<endl;
            //sleep_for(chrono::milliseconds(10));
        }
        //m.unlock();
        i++;
        //sleep_for(chrono::milliseconds(1));
    }
}
void Alarm()
{
    cout << "calarm  " << this_thread::get_id() << "  created" << endl;
    sleep_for(chrono::milliseconds(10000));
    cout << "Alarm!!!" << endl;
}

void C_Alarm()
{
    
}

void echo()
{
    string text = "";
    cin >> text;
    cout << text << endl;
}


int main(int argc, const char * argv[]) {
    ///////////Реализовать выполнение двух функций (f1, f2) в отдельных потоках///////////
    /*
    thread t1(f1);
    thread t2(f2);
    t1.join();
    t2.join();
    */
    
    /*
    mutex m;
    thread t1(f3, ref(m));
    thread t2(f4, ref(m));
    t1.join();
    t2.join();
    */
    
    /*
    thread t1(f5);
    thread t2(f6);
    t1.join();
    t2.join();
    */
    
    /*  ////////Продемонстрировать случай взаимной блокировки потоков в ожидании мьютекса.////////////
    mutex m;
    thread t1(f7, ref(m));
    thread t2(f8, ref(m));
    t1.join();
    t2.join();
    */
    
    //////Продемонстровать случай взаимной блокировки потоков при ожидании их завершения (циклический join).////////
    
    
    //////Реализовать командный процессор, поддерживающий выполнение следующих функций: echo
    /*
    thread t1(Alarm);
    thread t2(echo);
    
    t1.join();
    t2.join();
    */
    
    ///calarm, start, cancel -- функция установки, запуска и сброса таймера, выводящего сообщение о завершении по истечении указанного промежутка времени///
    
    
    
    
    
    return 0;
}