/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  一些类型的定义
 *
 *        Version:  1.0
 *        Created:  2015年7月22日 10时07分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *
 * =====================================================================================
 */

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include "types.h"

// 端口写一个字节
void outb(uint16_t port, uint8_t value);

// 端口读一个字节
uint8_t inb(uint16_t port);

// 端口读一个字
uint16_t inw(uint16_t port);

#endif // INCLUDE_COMMON_H_
